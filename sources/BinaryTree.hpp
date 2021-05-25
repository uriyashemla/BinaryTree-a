
#pragma once

#include <stack>
#include <queue>
using namespace std;

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>


namespace ariel
{
    template <class T>
    class BinaryTree
    {

        class Node
        {
        public:
            T data;
            Node *left = nullptr;
            Node *right = nullptr;

            Node(T d) : data(d), left(nullptr), right(nullptr) {}
        };
        Node *root;

    public:
        BinaryTree<T>() : root(nullptr) {}

        BinaryTree<T> add_root(T d)
        {
            if (root == nullptr)
            {
                root = new Node(d);
            }
            else
            {
                root->data = d;
            }
            return *this;
        }

        BinaryTree<T> add_left(const T &data, const T &l)
        {
            Node *temp = is_exist(data);
            if (temp == nullptr)
            {
                throw std::invalid_argument{"the Node doesnt exist"};
            }
            if (temp->left == nullptr)
            {
                temp->left = new Node(l);
            }
            else
            {
                temp->left->data = l;
            }
            return *this;
        }

        BinaryTree<T> add_right(const T &data, const T &r)
        {
            Node *temp = is_exist(data);
            if (temp == nullptr)
            {
                throw std::invalid_argument{"the Node doesnt exist"};
            }
            if (temp->right == nullptr)
            {
                temp->right = new Node(r);
            }
            else
            {
                temp->right->data = r;
            }
            return *this;
        }

        Node *is_exist(T data)
        {
            if (root == NULL)
            {
                return nullptr;
            }
            stack<Node *> nodeStack;
            nodeStack.push(root);
            Node *node = nodeStack.top();
            while (nodeStack.empty() == false)
            {
                node = nodeStack.top();
                nodeStack.pop();
                if (node->data == data)
                {
                    return node;
                }
                if (node->right)
                    nodeStack.push(node->right);
                if (node->left)
                    nodeStack.push(node->left);
            }
            return nullptr;
        }

        class inorder
        {
        public:
            stack<Node *> in_s;
            queue<Node *> in_tor;
            Node *in_cur;

            inorder(Node *ptr = nullptr)
            {
                in_cur = ptr;
                if (in_cur == nullptr)
                {
                }
                else
                {
                    while (in_cur != NULL || in_s.empty() == false)
                    {
                        while (in_cur != NULL)
                        {
                            in_s.push(in_cur);
                            in_cur = in_cur->left;
                        }

                        /* Current must be NULL at this point */
                        in_cur = in_s.top();
                        in_s.pop();
                        in_tor.push(in_cur);

                        in_cur = in_cur->right;
                    }
                }
            }

            inorder &operator++()
            {
                in_tor.pop();
                this->in_cur = in_tor.front();
                return *this;
            }
            inorder &operator++(int)
            {
                in_tor.pop();
                this->in_cur = in_tor.front();
                return *this;
            }
            T *operator->()
            {
                return &(in_tor.front()->get_data());
            }
            const T &operator*() const
            {
                return in_cur->data;
            }
            bool operator==(const inorder &other) const
            {
                return in_cur == other.in_cur;
            }
            bool operator!=(const inorder &other) const
            {
                return in_cur != other.in_cur;
            }
        };

        inorder begin_inorder()
        {
            return inorder(root);
        }

        inorder end_inorder()
        {
            return (nullptr);
        }

        inorder begin()
        {
            return inorder(root);
        }

        inorder end()
        {
            return (nullptr);
        }

        class preorder
        {

        public:
            stack<Node *> pre_s;
            queue<Node *> pre_tor;
            Node *pre_cur;

            preorder(Node *ptr = nullptr)
            {
                pre_cur = ptr;
                if (pre_cur == nullptr)
                {
                }
                else
                {
                    while (pre_s.empty() == false)
                    {
                        pre_cur = pre_s.top();
                        pre_s.pop();
                        pre_tor.push(pre_cur);

                        // Push right and left children of the popped node to stack
                        if (pre_cur->right)
                            pre_s.push(pre_cur->right);
                        if (pre_cur->left)
                            pre_s.push(pre_cur->left);
                    }
                }
            }

            preorder &operator++()
            {
                pre_tor.pop();
                this->pre_cur = pre_tor.front();
                return *this;
            }
            preorder &operator++(int)
            {
                pre_tor.pop();
                this->pre_cur = pre_tor.front();
                return *this;
            }
            T *operator->()
            {
                return &(pre_tor.front()->data);
            }
            const T &operator*() const
            {
                return pre_cur->data;
            }
            bool operator==(const preorder &other) const
            {
                return pre_cur == other.pre_cur;
            }
            bool operator!=(const preorder &other) const
            {
                return pre_cur != other.pre_cur;
            }
        };

        preorder begin_preorder()
        {
            return preorder(root);
        }

        preorder end_preorder()
        {
            return (nullptr);
        }

        class postorder
        {

        public:
            stack<Node *> pos_s1;
            stack<Node *> pos_s2;
            queue<Node *> pos_tor;
            Node *pos_cur;

            postorder(Node *ptr = nullptr)
            {
                pos_cur = ptr;
                if (pos_cur == nullptr)
                {
                }
                else
                {
                    pos_s1.push(pos_cur);
                    while (!pos_s1.empty())
                    {

                        pos_cur = pos_s1.top();
                        pos_s1.pop();
                        pos_s2.push(pos_cur);
                        if (pos_cur->left)
                            pos_s1.push(pos_cur->left);
                        if (pos_cur->right)
                            pos_s1.push(pos_cur->right);
                    }

                    // Print all elements of second stack
                    while (!pos_s2.empty())
                    {
                        pos_cur = pos_s2.top();
                        pos_s2.pop();
                        pos_tor.push(pos_cur);
                    }
                }
            }
            postorder &operator++()
            {
                pos_tor.pop();
                this->pos_cur = pos_tor.front();
                return *this;
            }
            postorder &operator++(int)
            {
                pos_tor.pop();
                this->pos_cur = pos_tor.front();
                return *this;
            }
            T *operator->()
            {
                return &(pos_tor.front()->data);
            }
            const T &operator*() const
            {
                return pos_cur->data;
            }
            bool operator==(const postorder &other) const
            {
                return pos_cur == other.pos_cur;
            }
            bool operator!=(const postorder &other) const
            {
                return pos_cur != other.pos_cur;
            }
        };

        postorder begin_postorder()
        {
            return postorder(root);
        }

        postorder end_postorder()
        {
            return (nullptr);
        }

        friend std::ostream &operator<<(std::ostream &out, const BinaryTree<T> &btree)
        {
            out << endl;
            return out;
        }
    };

}