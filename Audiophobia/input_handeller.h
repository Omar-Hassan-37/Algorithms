#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include "Edge.h"
#include "Query.h"

int inputInteger(std::string message, const int &lowerBound, const int &upperBound)
{
    std::string userInput = "";
    int enteredInput = 0;
    while (true)
    {
        std::cout << message;
        std::getline(std::cin, userInput);
        try
        {
            enteredInput = std::stoi(userInput);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Not a number." << std::endl;
            continue;
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Too big number to store, enter a smaller one." << std::endl;
            continue;
        }
        if (enteredInput >= lowerBound && enteredInput <= upperBound)
        {
            return enteredInput;
        }
        else
        {
            std::cerr << "Out of range, must be between inclusively " << lowerBound << " & " << upperBound << "." << std::endl;
        }
    }
}

std::vector<int> inputFirstLine()
{
    std::vector<int> line;
    int integer = inputInteger("Enter the number of crossings :", 0, 100);
    line.push_back(integer);
    integer = inputInteger("Enter the number of streets :", 0, 1000);
    line.push_back(integer);
    integer = inputInteger("Enter the number of queries :", 0, 10000);
    line.push_back(integer);

    return line;
}

std::vector<Edge> inputEdges(const int &crossings, const int &streets)
{
    std::vector<Edge> edges(streets);
    std::cout << "Enter the edges, press enter after every edge." << std::endl;
    std::cout << "For every edge enter the start, end crossings and noise in decibels separated by spaces." << std::endl;
    for (int i = 0; i < streets; i++)
    {
        Edge tempEdge;
        while (true)
        {
            std::cout << "Enter the edge #" << i + 1 << std::endl;
            std::cin >> tempEdge;
            if (tempEdge.getStart() > crossings || tempEdge.getStart() <= 0 || tempEdge.getEnd() > crossings || tempEdge.getEnd() <= 0)
            {
                std::cerr << "At least One of the crossings is out of range." << std::endl;
            }
            else if (tempEdge.getStart() == tempEdge.getEnd())
            {
                std::cerr << "Start crossing can't be the same as the end crossing." << std::endl;
            }
            else if (tempEdge.getDecibels() < 0)
            {
                std::cerr << "The noise can't be negative." << std::endl;
            }
            else
            {
                break;
            }
        }
        edges[i] = tempEdge;
    }
    return edges;
}

std::vector<Query> inputQueries(const int &crossings, const int &numberOfQueries)
{
    std::vector<Query> queries(numberOfQueries);
    std::cout << "Enter the queries, press enter after each query." << std::endl;
    std::cout << "For each query, enter the start and the end crossings separated by space." << std::endl;
    for (int i = 0; i < numberOfQueries; i++)
    {
        Query tempQuery;
        while (true)
        {
            std::cin >> tempQuery;
            if (tempQuery.getStart() <= 0 || tempQuery.getStart() > crossings || tempQuery.getEnd() <= 0 || tempQuery.getEnd() > crossings)
            {
                std::cerr << "At least one crossing is out of range." << std::endl;
            }
            else if (tempQuery.getStart() == tempQuery.getEnd())
            {
                std::cerr << "Start crossing can't be equl to end crossing." << std::endl;
            }
            else
            {
                break;
            }
        }
        queries[i] = tempQuery;
    }
    return queries;
}