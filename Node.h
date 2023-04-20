class Node
{
public:
    int value;
    int height;
    Node *left;
    Node *right;

    Node(int k)
    {
        value = k;
        height = 1;
        left = nullptr;
        right = nullptr;
    }

    ~Node()
    {
        delete left;
        delete right;
    }
};