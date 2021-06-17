package com.company;

import java.util.*;

public class Tree2 {

    Node root;

    public void addNode(int x) {
        Node newNode = new Node(x);

        if (root == null) {
            root = newNode;
        } else {
            Queue <Node> q = new LinkedList();
            q.add(root);
            Node currentNode;

            while (!q.isEmpty()){
                currentNode = q.poll();
                if(currentNode.left == null){
                    currentNode.left = newNode;
                    break;
                }
                else{
                    q.add(currentNode.left);
                }
                if(currentNode.right == null){
                    currentNode.right = newNode;
                    break;
                }
                else{
                    q.add(currentNode.right);
                }
            }
        }
    }

    public ArrayList<Integer> checkNumber(Tree2 T){
        ArrayList <Integer> list = new ArrayList();
        ArrayList <Integer> getLargest = new ArrayList();
        int max;
        Queue<Node> q = new LinkedList<Node>();
        q.add(root);

        while(true){
            if(!getLargest.isEmpty()){
                max = Collections.max(getLargest);
                list.add(max);
            }
            int size = q.size();
            if(size == 0){
                break;
            }
            getLargest.clear();

            while (size > 0) {
                Node currentNode = q.poll();
                //System.out.println(currentNode.value + " ");
                getLargest.add((Integer) currentNode.value);
                if(currentNode.left != null){
                    q.add(currentNode.left);
                }
                if(currentNode.right != null){
                    q.add(currentNode.right);
                }
                size--;
            }
            //System.out.println();
        }

        return list;
    }
}


