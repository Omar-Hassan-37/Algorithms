package com.company;


import java.util.*;

public class Main {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int size;
        int input;
        size = in.nextInt();
        Tree2 T = new Tree2();
        ArrayList<Integer> arry = new ArrayList();

        for(int i = 0; i < size; i++) {
            input = in.nextInt();
            T.addNode(input);
        }

        arry = T.checkNumber(T);

        for(int i:arry) {
            System.out.println(i);
        }
    }

}