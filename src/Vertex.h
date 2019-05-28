#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <string>

#include "Edge.h"
#include "Coordinates.h"
#include "MutablePriorityQueue.h"



class Vertex {
    
private:

    int id;
    Coordinates coords;
    std::vector<Edge*> paths;
    
    bool visited = false;
    Edge *lastEdge = nullptr;
    int queueIndex = 0;
    Time time;    

public:
    /**
     * @brief Construct a new Vertex
     * 
     * @param id of the vertex
     * @param Coodinate X
     * @param Coordinate Y
     */
    Vertex(int id, double x, double y);

    /**
     * @brief Construct a new Vertex object
     * 
     */
    Vertex() { }

    /**
     * @brief Get the Coordinates object
     * 
     * @return Coordinates of the Vertex 
     */
    Coordinates getCoordinates() const;

    /**
     * @brief Get the Coordinate X
     * 
     * @return double with X coordinate
     */
    double getX() const;

    /**
     * @brief Get the Coordinate Y
     * 
     * @return double with Y coordinate
     */
    double getY() const;
    
    /**
     * @brief Get the id of the vertex
     * 
     * @return int with the id
     */
    int getID() const;

    /**
     * @brief Get the Time of the Vertex
     * 
     * @return Time 
     */
    Time getTime() const;

    /**
     * @brief Set the Time of the Vertex
     * 
     * @param newTime to set
     */
    void setTime(Time newTime);
    
    /**
     * @brief Get the Last Edge
     * 
     * @return Edge* pointer to the edge
     */
    Edge* getLastEdge() const;

    /**
     * @brief Set the Last Edge object
     * 
     * @param edge
     */
    void setLastEdge(Edge* edge);

    /**
     * @brief Get the Visited, important for the implemention of the algorithms
     * 
     * @return true if visited
     * @return false if not visited
     */
    bool getVisited() const;

    /**
     * @brief Set the Visited
     * 
     * @param boolean with the value we want to set
     */
    void setVisited(bool visited);

    /**
     * @brief Set the Last Edge Type
     * 
     * @param edgeType we want to set
     */
    void setLastEdgeType(Type edgeType);

    /**
     * @brief Calculate the time that would take to travel from one vertex to another by subway and in a straight line
     * 
     * @param vertex    Pointer to the vertex to travel to
     * @return Time     Time of the trip
     */
    Time getAverageTime(Vertex const *vertex) const;

    /**
     * @brief method to add a Edge to the vertex, connecting 2 vertexs
     * 
     * @param edge we want to add
     */
    void addEdge(Edge *edge);

    /**
     * @brief Get the Num Edges
     * 
     * @return size_t with the number of Edges
     */
    size_t getNumEdges();

    /**
     * @brief Get the Edge object
     * 
     * @param index we want to look
     * @return Edge* at that index
     */
    Edge* getEdge(size_t index);
    
    /**
     * @brief Overload of the operator less
     * 
     * @param vertex we want to compare
     * @return true if less
     * @return false if great or equal
     */
    bool operator<(Vertex const &vertex) const;

    friend class Edge;
    friend class Graph;
    friend class MutablePriorityQueue<Vertex>;
};


#endif
