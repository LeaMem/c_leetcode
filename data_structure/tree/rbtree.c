#include <stdlib.h>
#include <stdio.h>

#define RED 0    //红色节点
#define BLACK 1  //黑色节点

#define rb_parent(r) ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r) ((r)->color == RED)
#define rb_is_black(r) ((r)->color == BLACK)
#define rb_set_black(r)     \
    do {                    \
        (r)->color = BLACK; \
    } while (0)
#define rb_set_red(r)     \
    do {                  \
        (r)->color = RED; \
    } while (0)
#define rb_setparent(r, p) \
    do {                   \
        (r)->parent = (p); \
    } while (0)
#define rb_set_color(r, c) \
    do {                   \
        (r)->color = (c);  \
    } while (0)

typedef int Type;

// 红黑树的节点
typedef struct RBTreeNode {
    unsigned char color;  //颜色 (RED || BLACK)
    Type key;
    struct RBTreeNode *left;
    struct RBTreeNode *right;
    struct RBTreeNode *parent;
} Node, *RBTree;

//红黑树的根
typedef struct rb_root {
    Node *node;
} RBRoot;

/**
 *      创建红黑树，返回红黑树的根
 */
RBRoot *create_rbtree() {
    RBRoot *root = malloc(sizeof(RBRoot));
    root->node = NULL;
    return root;
}

/**
 *      递归查找红黑树中键值为key的节点
 */
static Node *search(RBTree x, Type key) {
    if (x == NULL || x->key == key) {
        return x;
    }
    if (key < x->key) {
        return search(x->left, key);
    } else {
        return search(x->right, key);
    }
}

// int rbtree_search(RBRoot * root, Type key){
//     if(root){
//         return search(root->node, key) ? 0 : -1;
//     }
// }

/**
 *      非递归查找红黑树中键值为key的节点
 */
static Node *interative_search(RBTree x, Type key) {
    while (x != NULL && x->key != key) {
        if (key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    return x;
}

/**
 *      查询最小节点，返回 tree 为根节点的红黑树的最小节点
 */
static Node *minimum(RBTree tree) {
    if (tree == NULL) {
        return NULL;
    }
    while (tree->left) {
        tree = tree->left;
    }
    return tree;
}

int rbtree_minimum(RBRoot *root, int *val) {
    Node *node;
    if (root) {
        node = minimum(root->node);
    }
    if (node == NULL) {
        return -1;
    }
    *val = node->key;
    return 0;
}

/**
 * 查找最大节点，返回 tree 为根节点的红黑树的最大节点
 */
static Node *maximum(RBTree tree) {
    if (tree == NULL) {
        return NULL;
    }
    while (tree->right != NULL) {
        tree = tree->right;
    }
    return tree;
}

int rbtree_maximum(RBRoot *root, int *val) {
    Node *node;
    if (root) {
        node = maximum(root->node);
    }
    if (node == NULL) {
        return -1;
    }
    *val = node->key;
    return 0;
}

/**
 *      查找节点 x 的后继节点 ==> 查找红黑树中数值大于该节点的最小节点
 */
static Node *rbtree_successor(RBTree x) {
    //如果存在右孩子，则 x的后集结点 为根节点的红黑树的最小节点
    if (x->right != NULL) {
        return minimum(x->right);
    }

    //如果没有右孩子，则x有两种可能
    // 1. x是一个左孩子，则 x的后继节点为 它的父节点
    // 2. x是一个右孩子，则查找
    // x的最低父节点，并且该父节点要有左孩子，找到的这个最低的父节点就是x的后继节点
    Node *y = x->parent;
    while (y != NULL && x == y->right) {
        x = y;
        y = y->parent;
    }

    return y;
}

/**
 *  找节点 x 的前驱节点 ==> 查找红黑树中数据小于该节点的最大节点
 */
static Node *rbtree_predecessor(RBTree x) {
    if (x->left != NULL) {
        return maximum(x->left);
    }

    Node *y = x->parent;
    while (y != NULL && x == y->left) {
        x = y;
        y = y->parent;
    }

    return y;
}

static void rbtree_left_rotate(RBRoot *root, Node *x) {
    Node *y = x->right;

    x->right = y->left;
    if (y->left != NULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        root->node = y;
    } else {
        if (x->parent->left == x) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
    }

    y->left = x;

    x->parent = y;
}

static void rbtree_right_rotate(RBRoot *root, Node *y) {
    Node *x = y->left;
    y->left = x->right;
    if (x->right != NULL) {
        x->right->parent = y;
    }

    x->parent = y->parent;
    if (y->parent == NULL) {
        root->node = x;
    } else {
        if (y == y->parent->right) {
            y->parent->right = x;
        } else {
            y->parent->left = x;
        }
    }

    x->right = y;
    y->parent = x;
}

/**
 *      红黑树插入修改正函数
 *      在向红黑树中插入节点后(失去平衡)，再调用该函数;
 *      目的是将它重新塑造成一颗红黑树
 * 参数说明：
 *      root 红黑树的根
 *      node 插入的节点
 */
static void rbtree_insert_fixup(RBRoot *root, Node *node) {
    Node *parent, *gparent;

    // 若 父节点存在，并且父节点的颜色是红色
    while ((parent = rb_parent(node)) && rb_is_red(parent)) {
        gparent = rb_parent(parent);

        // 若父节点是祖父节点的左孩子
        if (parent == gparent->left) {
            // case1: 叔叔节点是红色
            {
                Node *uncle = gparent->right;
                if (uncle && rb_is_red(uncle)) {
                    rb_set_black(uncle);
                    rb_set_black(parent);
                    rb_set_red(gparent);
                    node = gparent;
                    continue;
                }
            }

            // case2: 叔叔是黑色，且当且节点是右孩子
            if (parent->right == node) {
                Node *tmp;
                rbtree_left_rotate(root, parent);
                tmp = parent;
                parent = node;
                node = tmp;
            }

            // case3: 叔叔是黑色，且当前节点是左孩子
            rb_set_black(parent);
            rb_set_red(gparent);
            rbtree_right_rotate(root, gparent);
        } else {
            //若z的父节点是z的父节点的右孩子

            // case1: 叔叔节点是红色
            {
                Node *uncle = gparent->left;
                if (uncle && rb_is_red(uncle)) {
                    rb_set_black(uncle);
                    rb_set_black(parent);
                    rb_set_red(gparent);
                    node = gparent;
                    continue;
                }
            }

            // case2: 叔叔是黑色，且当前节点是左孩子
            if (parent->left == node) {
                Node *tmp;
                rbtree_right_rotate(root, parent);
                tmp = parent;
                parent = node;
                node = tmp;
            }

            // case3: 叔叔是黑色，且当前节点是右孩子
            rb_set_black(parent);
            rb_set_red(gparent);
            rbtree_left_rotate(root, gparent);
        }
    }

    //将根节点设置为黑色
    rb_set_black(root->node);
}

/**
 *      添加节点：
 * 参数说明：
 *      root 红黑树的根
 *      node 插入的节点
 */
static void rbtree_insert(RBRoot *root, Node *node) {
    Node *y = NULL;
    Node *x = root->node;

    while (x != NULL) {
        y = x;
        if (node->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    rb_parent(node) = y;
    if(y != NULL){
        if(node -> key < y->key){
            y->left = node;
        }else{
            y->right = node;
        }
    }else{
        //如果是空节点，则将node设置为根节点
        root->node = node;
    }
    
    //设置节点的颜色为红色
    node->color = RED;

    rbtree_insert_fixup(root, node);

}

static Node * create_rbtree_node(Type key, Node * parent, Node * left, Node * right){
    Node * p = malloc(sizeof(Node));
    p->key = key;
    p->left = left;
    p->right = right;
    p->parent = parent;
    p->color = BLACK;
    return p;
}

int insert_rbtree(RBRoot * root, Type key){
    Node * node;
    //不允许插入键值相同的节点
    //(若不想插入相同键值的节点，注释掉下面两句)
    if(search(root->node, key) != NULL){
        return -1;
    }

    node = create_rbtree_node(key, NULL, NULL, NULL);

    rbtree_insert(root, node);
    return 0;
}