#include "/home/dvya/Documents/Adslab/include/BST.h"
#include<iostream>

using namespace std;

template<class T>
BSTNode<T>::BSTNode(T data)
{
    this->data= data;
    this->left= NULL;
    this->right= NULL;
    //ctor
}

template <class T>
void BSTNode<T>::Display()
{
    cout<<data;
}

template<class T>
BSTNode<T>::~BSTNode()
{
    //dtor
}

template<class T>
BST<T>::BST()
{
    Root= NULL;
    //ctor
}

template<class T>
BST<T>::BST(T data)
{
    Root= new BSTNode<T>(data);
    //ctor
}


//INSERT

template<class T>
void BST<T>::Insert(T data)
{
    Root= Insertt(data,Root);
}

template<class T>
BSTNode<T>* BST<T>::Insertt(T data,BSTNode<T>* node)
{
    if(node == NULL)
    {
        return new BSTNode<T>(data);

    }
    else if(data < node->data)
        node->left= Insertt(data,node->left);
    else if(data >= node->data)
        node->right= Insertt(data,node->right);
    return node;

}

//INORDER

template<class T>
void BST<T>::Inorder()
{
    display_Inorder(Root);
}

template<class T>
void BST<T>:: display_Inorder(BSTNode<T>* node)
{
    if(node == NULL)
        return;
    display_Inorder(node->left);
    cout<< node->data << " ";
    display_Inorder(node->right);
}

//PREORDER

template<class T>
void BST<T>::Preorder()
{
    display_Preorder(Root);
}

template<class T>
void BST<T>::display_Preorder(BSTNode<T>* node)
{
    if(node != NULL)
    {
        node->Display();
        std::cout<<" ";
        display_Preorder(node->left);
        display_Preorder(node->right);
    }

}

//POSTORDER

template<class T>
void BST<T>::Postorder()
{
    display_Postorder(Root);
}

template<class T>
void BST<T>::display_Postorder(BSTNode<T>* node)
{
    if(node != nullptr)
    {
        display_Postorder(node->left);
        display_Postorder(node->right);
        std::cout << node->data << " ";

    }

}


//SEARCH

template<class T>
void BST<T>::Search(T data)
{
     Searchh(data,Root);

}


template<class T>
void BST<T>::Searchh(T data, BSTNode<T>* node)
{
        if(node == NULL)
           cout<< "\n\nOPPS!! NOTFOUND";
            //return NULL;
        else if(data == node->data)
                cout<< "\n\nFOUND";
        else if(data < node->data)
             Searchh(data, node->left);
        else if(data > node->data)
             Searchh(data, node->right);
        else
            cout<< "Invalid Input";
}
//FINDINGMINIMUM

template<class T>
BSTNode<T>* BST<T>::FindMin(BSTNode<T>* node)
{
    BSTNode<T>* current=node;
    while(current->left !=NULL)
       current=current->left;
    return current;

}
//DELETE

template<class T>
void BST<T>::Delete(T data)
{
    Del(Root,data);


}

template<class T>
BSTNode<T>* BST<T>::Del(BSTNode<T>* node, T data)
{
   if(node==NULL)               //base case
   {
       cout<< "\nINVALID INPUT !!\n";
        return node;
   }

   if(data<node->data)          //if data is smaller than root
     node->left=Del(node->left,data);
   else if(data>node->data)     //if data is greater than root
     node->right=Del(node->right,data);
   else                             //if data is same as root
   {
       if(node->left==NULL)             //node with one or no child
       {
           BSTNode<T>* temp=node->right;
           free(node);
           cout<< "\nDeleted Successfully !!\n";
           return temp;
       }
       else if(node->right==NULL)
       {
           BSTNode<T>* temp=node->left;
           free(node);
           cout<< "\nDeleted Successfully !!\n";
           return temp;
       }
       BSTNode<T>* temp=FindMin(node->right);           //node with two children
       node->data=temp->data;
       node->right=Del(node->right,temp->data);


   }
    return node;



}
template<class T>
BST<T>::~BST()
{
    //dtor
}


