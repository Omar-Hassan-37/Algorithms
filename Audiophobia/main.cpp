#include <iostream>
#include "input_handeller.h"
#include "Edge.h"
#include "Query.h"

template <class T>
void printVector(const std::vector<T> &);
bool terminateCase(const std::vector<int> &);
std::vector<int> solveQueries(const std::vector<int> &, const std::vector<Edge> &, const std::vector<Query> &);

int main()
{
    int caseNumber = 1;
    while (true)
    {
        std::vector<int> firstLine = inputFirstLine();
        if(terminateCase(firstLine)) 
        {
            break;
        }
        std::vector<Edge> edges = inputEdges(firstLine[0], firstLine[1]);
        std::vector<Query> queries = inputQueries(firstLine[0], firstLine[2]);
        std::cout << "Case #" << caseNumber << std::endl;
        std::vector<int> queriesAnswers = solveQueries(firstLine, edges, queries);
        for(int queryAnswer : queriesAnswers)
        {
            std::cout << queryAnswer << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}

template <class T>
void printVector(const std::vector<T> &vect)
{
    for (T item : vect)
    {
        std::cout << item << std::endl;
    }
}

bool terminateCase(const std::vector<int> &vect)
{
    if(vect[0] == 0 && vect[1] == 0 && vect[2] == 0)
    {
        return true;
    }
    return false;
}

std::vector<int> solveQueries(const std::vector<int> &firstLine, const std::vector<Edge> &edges, const std::vector<Query> &queries)
{
    std::vector<int> answers(queries.size());

    return answers;
}