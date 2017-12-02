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
		nullptr,	// Next node in solution path
	};
	// Add the starting node to the priority queue to open when running the algorithm.
	mPriorityQueue.insert(startNode, startNode.totalCost);
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
}

AiNode BFSearch::run()
{
}

int BFSearch::getCostOfGoingTo(const AiState &node) const
{
	if (mSearchType == LeastCost)
		throw std::exception("NOT IMPLEMENTED!");
	return mUniformCost;
}
