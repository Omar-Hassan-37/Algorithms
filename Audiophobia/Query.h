#pragma once

#include <iostream>
#include <climits>

class Query
{
private:
    int start;
    int end;

public:
    Query();
    Query(const int &, const int &);
    const int &getStart() const;
    const int &getEnd() const;
    ~Query();
    friend std::ostream &operator<<(std::ostream &, const Query &);
    friend std::istream &operator>>(std::istream &, Query &);
};

Query::Query()
{
    this->start = 0;
    this->end = 0;
}
Query::Query(const int &start, const int &end)
{
    this->start = start;
    this->end = end;
}

const int &Query::getStart() const
{
    return start;
}

const int &Query::getEnd() const
{
    return end;
}

Query::~Query() {}

std::ostream &operator<<(std::ostream &out, const Query &query)
{
    out << query.start << " " << query.end;
    return out;
}

std::istream &operator>>(std::istream &in, Query &query)
{
    in >> query.start >> query.end;
    in.ignore(INT_MAX, '\n');
    return in;
}
