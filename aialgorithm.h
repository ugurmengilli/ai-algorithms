#ifndef AIALGORITHM_H
#define AIALGORITHM_H

#include <QObject>
#include <QList>
#include <QVector>
#include "aiproblem.h"

typedef QList<int> AiState;

struct AiNode
{
	int cost;				// Cost of this state
	int totalCost;			// Total cost until this state
	int step;				// The index of this state in solution path
	int openedNodeIndex;	// Index of this state in the list of opened nodes if it is opened
	AiState state;			// State of the board stored in this struct
	AiNode* previous;		// Back-pointer
	AiNode* next;			// Next step in optimum solution path. Use this to track the path from start to goal.
	QVector<AiState> successors;	// Stores currently closed nodes

	bool operator== (AiNode* node) {
		return this->state == node->state;
	}

	bool operator== (AiState& state) {
		return this->state == state;
	}

	bool operator< (AiNode* state) {
		return this->totalCost < state->totalCost;
	}
};

class AiAlgorithm : public QObject
{
	Q_OBJECT

public:
	AiAlgorithm(const AiProblem *problem, QObject *parent = 0) 
		: QObject(parent), mStart(problem->mStart), mGoal(problem->mGoal) { }
	virtual ~AiAlgorithm() { };

public slots:
	virtual AiNode run() = 0;

protected slots:
	virtual void addNewSuccessors(QVector<AiNode>& successors) = 0;
	virtual bool isGoal(AiNode& node) { return node == mGoal; };
	virtual void openNode(AiNode&) = 0;

protected:
	QVector<AiNode> mSetOpenNodes;
	QVector<AiNode> mPriorityQue;
	AiState mStart;
	AiState mGoal;
};

#endif // AIALGORITHM_H
