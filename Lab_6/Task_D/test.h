#include <iostream>
using namespace std;
#define capacity 9999991

struct nodeTest {
    int val;
    int points;
    unsigned char height;
    nodeTest* left = nullptr;
    nodeTest* right = nullptr;
};

unsigned char heightTest(nodeTest* p)
{
    return p?p->height:0;
}

int bfactorTest(nodeTest* p)
{
    return heightTest(p->right)-heightTest(p->left);
}

void fixheightTest(nodeTest* p)
{
    unsigned char hl = heightTest(p->left);
    unsigned char hr = heightTest(p->right);
    p->height = (hl>hr?hl:hr)+1;
}

nodeTest* rotaterightTest(nodeTest* p)
{
    nodeTest* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheightTest(p);
    fixheightTest(q);
    return q;
}

nodeTest* rotateleftTest(nodeTest* q)
{
    nodeTest* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheightTest(q);
    fixheightTest(p);
    return p;
}

nodeTest* balanceTest(nodeTest* p)
{
    fixheightTest(p);
    if( bfactorTest(p)==2 )
    {
        if( bfactorTest(p->right) < 0 )
            p->right = rotaterightTest(p->right);
        return rotateleftTest(p);
    }
    if( bfactorTest(p)==-2 )
    {
        if( bfactorTest(p->left) > 0  )
            p->left = rotateleftTest(p->left);
        return rotaterightTest(p);
    }
    return p;
}

nodeTest* insertTest(nodeTest* p, int k, int points)
{
    if( !p ) {
        nodeTest* gap_node = new nodeTest;
        gap_node->val = k;
        gap_node->height = 1;
        gap_node->points = points;
        return gap_node;
    }
    if( k<p->val)
        p->left = insertTest(p->left,k, points);
    else
        p->right = insertTest(p->right,k, points);
    return balanceTest(p);
}

nodeTest* exists(int val, nodeTest* gap_root) {
    if (gap_root == nullptr || gap_root->val == val) {
        return gap_root;
    } else if (gap_root->val > val) {
        return exists(val, gap_root->left);
    } else {
        return exists(val, gap_root->right);
    }
}

nodeTest* checkInsertTest (nodeTest* gap_root, int k, int points) {
    nodeTest* newNode = exists(k, gap_root);
    if (newNode != nullptr) {
        return gap_root;
    } else {
        return insertTest(gap_root, k, points);
    }
}

nodeTest* maxElem (nodeTest* gap_root) {
    if (gap_root->right == nullptr) {
        return gap_root;
    } else {
        return maxElem(gap_root->right);
    }
}

nodeTest* remove(nodeTest* root, int k)
{
    if (root == nullptr) {
        return root;
    }
    if (k < root->val) {
        root->left = remove(root->left, k);
    } else if (k > root->val) {
        root->right = remove(root->right, k);
    } else if (root->left != nullptr && root->right != nullptr) {
        root->val = maxElem(root->left)->val;
        root->points = maxElem(root->left)->points;
        root->left = remove(root->left, root->val);
    } else {
        if (root->left != nullptr) {
            root = root->left;
        } else if (root->right != nullptr) {
            root = root->right;
        } else {
            root = nullptr;
        }
    }
    if (root == nullptr) {
        return root;
    }
    return balanceTest(root);
}

void summary(nodeTest* root, int& sum, int& count) {
    if (root != nullptr) {
        summary(root->left, sum, count);
        summary(root->right, sum, count);
        sum += root->points;
        count++;
    }
}

void maximum(nodeTest* root, int& maxPoints) {
    if (root != nullptr) {
        maximum(root->left, maxPoints);
        maximum(root->right, maxPoints);
        maxPoints = max(maxPoints, root->points);
    }
}

int hashFuncTest(int key){
    return key % capacity;
    //return (int) floor(capacity * fmod((sqrt(5) - 1) / 2 * key, 1));
}

int test() {
    int M, Q;
    cin >> M >> Q;
    nodeTest* roots[capacity];
    for (int i = 1; i <= M; i++) {
        roots[hashFuncTest(i)] = nullptr;
    }
    for (int i = 0; i < Q; i++) {
        char symb;
        cin >> symb;
        if (symb == '+') {
            int group, isu, points;
            cin >> group >> isu >> points;
            roots[hashFuncTest(group)] = insertTest(roots[hashFuncTest(group)], isu, points);
        } else if (symb == '-') {
            int group, isu;
            cin >> group >> isu;
            roots[hashFuncTest(group)] = remove(roots[hashFuncTest(group)], isu);

        } else if (symb == 'a') {
            int group;
            cin >> group;
            int sum = 0, count = 0;
            summary(roots[hashFuncTest(group)], sum, count);
            if (count == 0) {
                cout << 0 << "\n";
            } else {
                cout << sum / count << "\n";
            }
        } else if (symb == 'm') {
            int group;
            cin >> group;
            int maxPoints = 0;
            maximum(roots[hashFuncTest(group)], maxPoints);
            cout << maxPoints << "\n";
        }
    }
    return 0;
}
