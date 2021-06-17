#pragma once

#include <iostream>

class Edge
{
private:
    int start;
    int end;
    int decibels;

public:
    Edge();
    Edge(const int &, const int &, const int &);
    const int &getStart() const;
    const int &getEnd() const;
    const int &getDecibels() const;
    ~Edge();
    friend std::ostream &operator<<(std::ostream &, const Edge &);
    friend std::istream &operator>>(std::istream &, Edge &);
};

Edge::Edge()
{
    this->start = 0;
    this->end = 0;
    this->decibels = 0;
}

Edge::Edge(const int &start, const int &end, const int &decibels)
{
    this->start = start;
    this->end = end;
    this->decibels = decibels;
}

const int &Edge::getStart() const
{
    return start;
}

const int &Edge::getEnd() const
{
    return end;
}

const int &Edge::getDecibels() const
{
    return decibels;
}

Edge::~Edge() {}

std::ostream &operator<<(std::ostream &out, const Edge &edge)
{
    out << edge.start << " " << edge.end << " " << edge.decibels;
    return out;
}

std::istream &operator>>(std::istream &in, Edge &edge)
{
    in >> edge.start >> edge.end >> edge.decibels;
    in.ignore(INT_MAX, '\n');
    return in;
}
