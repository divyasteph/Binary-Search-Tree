#ifndef BST_H
#define BST_H
//#include "/home/dvya/Documents/Adslab/src/BST.cpp"

template<class T>
class BSTNode
{
    public:
        /** Default constructor */

        BSTNode* left;
        BSTNode* right;
        BSTNode(T data);
        T data;
        void Display();

        /** Default destructor */
        virtual ~BSTNode();

    protected:

    private:

};

template<class T>
class BST
{
public:
    BST();
    BST(T data);
    void Insert(T data);
    void Display();
    void Inorder();
    void Preorder();
    void Postorder();
    void Search(T data);
    void Delete(T data);
    void FindMin(T data);
    ~BST();

protected:

private:
    BSTNode<T>* Root;
    BSTNode<T>* Insertt(T data, BSTNode<T>* node);
    void display_Inorder(BSTNode<T>* node);
    void display_Postorder(BSTNode<T>* node);
    void display_Preorder(BSTNode<T>* node);
    void Searchh(T data, BSTNode<T>* node);
    BSTNode<T>* Del(BSTNode<T>* node, T data);
    BSTNode<T>* FindMin(BSTNode<T>* node);
};
#endif // BST_H

