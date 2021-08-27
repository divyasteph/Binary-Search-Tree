#include "/home/dvya/Documents/Adslab/src/BST.cpp"
#include <iostream>

using namespace std;

int main()
{
    cout << "\n_____BINARY SEARCH TREE______\n";

    BST<int>* tree= new BST<int>();

    int values[]={34,54,65,67,89,77,29};
    for(int i:values)
        tree->Insert(i);

    cout << "\nThe Values in the Tree\n";
    tree->Inorder();
    cout << "\n\nInorder Traversal \n";
    tree->Inorder();
    cout << "\n\nPreorder Traversal \n";
    tree->Preorder();
    cout << "\n\nPostorder Traversal \n";
    tree->Postorder();

    cout<< "\n\n1. SEARCH OR 2. DELETE ??\n";
    int a;
    cin>>a;
    if(a==1)
    {
        cout << "\n\nEnter the value to be searched: \n";
        int val;
        cin>>val;
        tree->Search(val);
    }
    else if(a==2)
    {
      cout << "\nEnter the value to be deleted: ";
      int valu;
      cin>>valu;
      tree->Delete(valu);
      cout<< "\nValues in the Tree...\n";
      tree->Inorder();

    }
    else
        cout<< "INVALID INPUT";

    std::cout<<std::endl;
    return 0;
}

