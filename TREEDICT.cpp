#include <iostream>
//#include<stack.h>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    string name;
    string meaning;
    node *left;
    node *right;
};

class bst
{
    public:
    node *root = NULL;
    node *temp, *temp1, *dummy,*parent;

    
    void insert(string word,string mean)
    {
        if (root == NULL)
        {
            cout << "tree is creating" << endl;
            root = (node *)malloc(sizeof(node));
            root->name = word;
            root->meaning = mean;
            root->left = NULL;
            root->right = NULL;
            cout << "root of the tree is :\t" << root->name << endl;
            dummy = root;
            exit;
        }
        else if (root->name >= word)
        {
            cout<<"word  "<<word << " is inserting at the left :" << root->name << endl;
            if(root->left == NULL)
            {
                temp = (node *)malloc(sizeof(node));
                temp->name = word;
                temp->meaning = mean;
                temp->left = NULL;
                temp->right = NULL;
                root->left = temp;
                exit;
            }
            else
            {
                while (root->left != NULL)
                {
                    cout << root->left->name << endl;
                    temp1 = root->left;
                    root = temp1;
                    cout << root->name << " new root" << endl;
                    insert(word,mean);
                    root = dummy;
                    break;
                }
            }
        }
        else
        {
            cout <<"word  "<<word << "  is inserting at the right : " << root->name << endl;

            if(root->right == NULL)
            {
                temp = (node *)malloc(sizeof(node));
                temp->name = word;
                temp->left = NULL;
                temp->right = NULL;
                root->right = temp;

            }
            else
            {
                while (root->right != NULL)
                {
                    temp1 = root->right;
                    root = temp1;
                    cout << root->name << " new root" << endl;
                    insert(word,mean);
                    root = dummy;
                    break;
                }        
            }
        }
    }

    bool search(string word) 
    {
       if(root == NULL)
       {
           cout<<"tree is empty"<<endl;
       }
       //cout<<"looking inside the tree"<<endl;
       if(root->name == word)
       {
           cout<<"word found"<<endl;
           cout<<"meaning of word is :\t"<<root->meaning<<endl;
           return 1;
       }
       else if(root->name < word) 
       {
           parent = root;
           root = root->right;
           search(word);
       }
       else if (root->name > word)
       {
           parent = root;
           root = root->left;
           search(word);
       }
    }


    void remove(string word)
    {
        cout<<"delete function called"<<endl;
        if((search(word)) == 1)
        
        {
           if(root->left == NULL && root->right == NULL)
           {
               delete root;
               cout<<"element deleted root has now no children"<<endl;
           } 
           else if(root->left == NULL || root->right == NULL)
           {
               if(root->left != NULL)
               {
                   dummy = root->left;
                   delete root;
                   parent->left = dummy;
               }
               else if(root->right != NULL)
               {
                   dummy = root->right;
                   delete root;
                   parent->right = dummy;
               }
           }
           else if(root->right != NULL && root->left != NULL)
           {
               cout<<"inorder succedor"<<endl;
               while(root->left != NULL)
               {
                   root = root->left;
               }
               dummy = root;
               cout<<"replaced with "<<dummy->name;
               parent = dummy;
               delete root;
           }
        }
    }


    void display(node *root)
    {
        // Base case
        if (root == NULL) 
        {
                return;
        }
        // Travel the left sub-tree first.
        display(root->left);
        // Print the current node value
        cout<<root->name<<":\t"<<root->meaning;
        // Travel the right sub-tree next.
        display(root->right);
    }

}; 




int main()
{
    
    bst ele;
    int per,cho;
    string word,mean;
    

    cout<<"---------------------------------------DASHBOARD STARTED HERE--------------------------------"<<endl;

    do
    {
        cout<<"1] TO INSERT LIST \n2] TO SEARCH ELEMENT IN THE LIST  \n3] TO DELETE ELEMENT OF THE LIST \n";
        cout<<"4]TO DISPALY ELEMENT OF THE LIST \n0] TO EXIT THE FUNCTION \n";
        cout<<"\n";
        cout<<"enter your choice :\t";
        cin>>cho;

        switch(cho)
        {
            case 1:
                do
                {
                    cout<<"enter the word to be insert :\t";
                    cin>>word;
                    cout<<"enter the meaning of the word :\t";
                    cin>>mean;
                    ele.insert(word,mean);
                    cout<<"do you want to added more words (0/1) :\t";
                    cin>>per;
                } while(per);

                
                break;
            case 2:
                cout<<"enter the word to be search :\t";
                cin>>word;
                ele.search(word);
                break;
            case 3:
                do
                {
                    cout<<"enter the word to be delete :\t";
                    cin>>word;
                    ele.remove(word);
                    cout<<"do you want to delete more words (0/1) :\t";
                    cin>>per;
                } while(per);
                break; 
            case 4:
                ele.display(ele.root);
                break;
            case 0:
                cout<<"EXITING \n";
                break;
            default :
                cout<<"ENTER THE VALID CHOICE \n";
                break; 
        }
    } while (cho != 0);

    return 0;
}