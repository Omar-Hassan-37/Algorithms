package com.company;
import java.util.*;

public class Tree{
    Node root;

    public void addLeftNode(int x){
        Node newNode = new Node(x);
        if(root == null){
            root = newNode;
        }
        else{
            Node currentNode = root;
            Node parent;
            while(true){
                parent = currentNode;
                if(currentNode.left == null){
                    currentNode = currentNode.left;
                    parent.left = newNode;
                    return;
                }
                else{
                    currentNode = currentNode.left;
                }
            }
        }
    }
    public void addRightNode(int x){
        Node newNode = new Node(x);
        if(root == null){
            root = newNode;
        }
        else{
            Node currentNode = root;
            Node parent;
            while(true){
                parent = currentNode;
                if(currentNode.right == null){
                    currentNode = currentNode.right;
                    parent.right = newNode;
                    return;
                }
                else{
                    currentNode = currentNode.right;
                }
            }
        }
    }

    public ArrayList <Integer> checkNumber(Tree T, int x){
        ArrayList <Integer>  list = new ArrayList();
        if(root == null) {
            return list;
        }
        else{
            Node leftNode = root;
            Node rightNode = root;
            Node currentNode = root;
            int y = x;
            while(true){
                if(leftNode != null && rightNode != null){
                    if((Integer)leftNode.value >= (Integer)rightNode.value){
                        list.add((Integer)leftNode.value);
                    }
                    else{
                        list.add((Integer)rightNode.value);
                    }
                }
                else if(leftNode == null && rightNode != null){
                    list.add((Integer)rightNode.value);
                }
                else if(rightNode == null && leftNode != null){
                    list.add((Integer)leftNode.value);
                }
                else{
                    return list;
                }
                x--;
                if(x > (y/2 - 1)){
                    leftNode = leftNode.left;
                    rightNode = rightNode.right;
                }
                else{
                    return list;
                }
            }
        }
    }
}