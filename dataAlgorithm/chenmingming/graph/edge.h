/**
 * @description: 边
 * @author: michael ming
 * @date: 2019/6/4 21:53
 * @modified by: 
 */

#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H
using namespace std;
template <class T>
class edge
{
public:
    virtual ~edge() {};
    virtual int vertex1() const = 0;
    virtual int vertex2() const = 0;
    virtual T weight() const = 0;
};
#endif //GRAPH_EDGE_H