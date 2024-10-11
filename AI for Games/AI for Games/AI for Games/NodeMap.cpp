#include "NodeMap.h"
#include "raylib.hpp"
#include <algorithm>

static bool CompareNode(Node* one, Node* two)
{
	return one->gScore < two->gScore;
}

//bool Node::operator==(const &Node other)
//{
//	if (one.connections == two.connections)
//	{
//		if (one.gScore == two.gScore)
//		{
//			if (one.position == two.position)
//			{
//				if (one.previous == two.previous)
//				{
//					return true;
//				}
//			}
//		}
//	}
//	else
//	{
//		return false;
//	}
//}

void NodeMap::Initialise(std::vector<std::string> asciiMap, int cellSize)
{
	m_cellSize = cellSize;
	const char emptySquare = '0';

	m_height = asciiMap.size();
	m_width = asciiMap[0].size();

	m_nodes = new Node * [m_width * m_height];

	for (int y = 0; y < m_height; y++)
	{
		std::string& line = asciiMap[y];
		if (line.size() != m_width)
		{
			std::cout << "Mismatched line #" << y << " in ASCII map (" << line.size() << " instead of " << m_width << ")" << std::endl;
		}

		for (int x = 0; x < m_width; x++)
		{
			char tile = x < line.size() ? line[x] : emptySquare;

			m_nodes[x + m_width * y] = tile == emptySquare ? nullptr : new Node(((float)x + 0.5f) * m_cellSize, ((float)y + 0.5f) * m_cellSize);
		}
	}

	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			Node* node = GetNode(x, y);
			if (node)
			{
				Node* nodeWest = x == 0 ? nullptr : GetNode(x - 1, y);
				if (nodeWest)
				{
					node->ConnectTo(nodeWest, 1);
					nodeWest->ConnectTo(node, 1);
				}

				Node* nodeSouth = y == 0 ? nullptr : GetNode(x, y - 1);
				if (nodeSouth)
				{
					node->ConnectTo(nodeSouth, 1);
					nodeSouth->ConnectTo(node, 1);
				}
			}
		}
	}
}

void NodeMap::Draw()
{
	Color cellColor;
	cellColor.a = 255;
	cellColor.r = 74;
	cellColor.g = 65;
	cellColor.b = 42;

	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			Node* node = GetNode(x, y);
			if (node == nullptr)
			{
				DrawRectangle((int)(x * m_cellSize), (int)(y * m_cellSize), (int)m_cellSize - 1, (int)m_cellSize - 1, cellColor);
			}
			else
			{
				for (int i = 0; i < node->connections.size(); i++)
				{
					Node* other = node->connections[i].target;
					DrawLine((x + 0.5f) * m_cellSize, (y + 0.5f) * m_cellSize, (int)other->position.x, (int)other->position.y, RAYWHITE);
				}
			}
		}
	}
}

void NodeMap::DrawPath(std::vector<Node*> path, Color lineColor)
{
	for ( int d = 1; d < path.size(); d++)
	{
		DrawLine(path[d]->position.x, path[d]->position.y, path[d - 1]->position.x, path[d - 1]->position.y, lineColor);
	}
}

std::vector<Node*> NodeMap::DijkstrasSearch(Node* startNode, Node* endNode)
{
	if ((startNode == nullptr) || (endNode == nullptr))
	{
		return std::vector<Node*>();
	}

	if (startNode == endNode)
	{
		return std::vector<Node*>();
	}
	
	startNode->gScore = 0;
	startNode->previous = nullptr;

	std::vector<Node*> openList;
	std::vector<Node*> closedList;
	Node* currentNode;

	openList.push_back(startNode);

	while (!openList.empty())
	{
		//Sort openList by Node.gScore COME BACK TO
		std::sort(openList.begin(), openList.end(), CompareNode);


		currentNode = openList.front(); //openList.front() potential? / or should be at(0)
		

		if (currentNode == endNode)
		{
			break;
		}

		//remove currentNode from openList COME BACK TO
		openList.erase(openList.begin());

		closedList.push_back(currentNode);

		for (int c = 0; c < currentNode->connections.size(); c++)
		{
			//if (currentNode->connections[c].target != std::find(closedList.at(1), closedList.at(closedList.size()), currentNode->connections[c].target))
			if(std::find(closedList.begin(), closedList.end(), currentNode->connections[c].target) == closedList.end())
			{
				int newGScore = currentNode->gScore + currentNode->connections[c].cost;

				//if (currentNode->connections[c].target != std::find(openList.at(1), openList.at(openList.size()), currentNode->connections[c].target))
				if(std::find(openList.begin(), openList.end(), currentNode->connections[c].target) == openList.end())
				{
					currentNode->connections[c].target->gScore = newGScore;
					currentNode->connections[c].target->previous = currentNode;
					openList.push_back(currentNode->connections[c].target);
				}
				else if (newGScore < currentNode->connections[c].target->gScore)
				{
					currentNode->connections[c].target->gScore = newGScore;
					currentNode->connections[c].target->previous = currentNode;
				}
			}
		}

	}

	std::vector<Node*> Path;
	currentNode = endNode;

	while (currentNode != nullptr)
	{
		Path.insert(Path.begin(), currentNode);
		currentNode = currentNode->previous;
	}

	return Path;
}

Node* NodeMap::GetClosestNode(glm::vec2 worldPos)
{
	int i = (int)(worldPos.x / m_cellSize);
	if (i < 0 || i >= m_width)
	{
		return nullptr;
	}

	int j = (int)(worldPos.y / m_cellSize);
	if (j < 0 || j >= m_height)
	{
		return nullptr;
	}

	return GetNode(i, j);
}