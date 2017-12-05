#include <exception>
#include "bfsearch.h"

BFSearch::BFSearch(AiProblem *problem, QObject *parent)
	: AiAlgorithm(problem, parent),	// Initializes start and goal states.
	mSearchType(UniformCost)
{
	AiNode startNode = {
		0,			// cost
		0,			// total cost
		0,			// step
		problem->getCurrentState(),		// state of the problem
		nullptr,	// Back-pointer
		nullptr		// Next node in solution path
	};
	// Add the starting node to the priority queue to open when running the algorithm.
	mPriorityQueue.insert(startNode.totalCost, startNode);
}

BFSearch::BFSearch(AiProblem *problem, BFSearch::BFStype type, QObject *parent)
	: BFSearch(problem, parent)
{
	mSearchType = type;
}

BFSearch::~BFSearch()
{
}

void BFSearch::open(AiNode &node)
{
	int index = mSetOfOpenNodes.indexOf(node);
	if (index > -1 && mSearchType == UniformCost)
		return;
	else if (index > -1 && mSearchType == LeastCost) {	// The node is already open
		if (node < mSetOfOpenNodes[index]) {
			mSetOfOpenNodes[index].totalCost = node.totalCost;	// Save the least-cost node replacing the higher-cost node.
			mSetOfOpenNodes[index].previous = node.previous;
		}
		return;			// since the node is already open
	}
	mSetOfOpenNodes.append(node);
	mProblem->setCurrentState(node.state);
	QVector<AiState> successors;
	mProblem->getSuccessors(successors);

	if (successors.isEmpty())
		return;	// to open next node in priority queue

	foreach(const AiState &successor, successors) {
		int cost = getCostOfGoingTo(successor);
		// Set new node corresponding to a successor state
		AiNode newNode = {
			cost,
			node.totalCost + cost,
			node.step + 1,
			successor,
			&(mSetOfOpenNodes.last()),
			nullptr
		};
		// Insert the new node at the end of the queue so that it can be opened later.
		mPriorityQueue.insertMulti(newNode.totalCost, newNode);
	}
}

AiNode BFSearch::run()
{
	while (mPriorityQueue.count()) {	// Loop until there is no node to be opened
		AiNode node = mPriorityQueue.take(mPriorityQueue.firstKey());

		if (foundGoalAt(node))
			return node;
		// Otherwise:
		open(node);
	}
	return AiNode();
}

int BFSearch::getCostOfGoingTo(const AiState &node) const
{
	if (mSearchType == LeastCost)
		throw std::exception("NOT IMPLEMENTED!");
	return mUniformCost;
}
