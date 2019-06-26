/**
 * @description: 抽象图类
 * @author: michael ming
 * @date: 2019/6/4 21:54
 * @modified by: 
 */

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
template <class T>
class graph
{
public:
    virtual ~graph(){}
    virtual int numberOfVertices() const = 0;
    virtual int numberOfEdges() const = 0;
    virtual bool existsEdge(int, int) const = 0;
    virtual void insertEdge(edge<T>*) = 0;
    virtual void eraseEdge(int, int) = 0;
    virtual int degree(int) const = 0;
    virtual int inDegree(int) const = 0;
    virtual int outDegree(int) const = 0;
};
#endif //GRAPH_GRAPH_H
