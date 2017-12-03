#ifndef AIALGORITHM_H
#define AIALGORITHM_H

#include <QObject>
#include <QList>
#include <QMap>
#include <QVector>
#include <QMap>
#include "aiproblem.h"

typedef QList<int> AiState;

struct AiNode
{
	int cost;				// Cost of this state
	int totalCost;			// Total cost until this state
	int step;				// The index of this state in solution path
	AiState state;			// State of the board stored in this struct
	AiNode* previous;		// Back-pointer
	AiNode* next;			// Next step in optimum solution path. Use this to track the path from start to goal.

	bool operator== (const AiNode &node) {
		return this->state == node.state;
	}

	bool operator== (const AiState &state) {
		return this->state == state;
	}

	bool operator< (const AiNode &state) {
		return this->totalCost < state.totalCost;
	}
};

class AiAlgorithm : public QObject
{
	Q_OBJECT

public:
	AiAlgorithm(AiProblem *problem, QObject *parent = 0) 
		: QObject(parent), mProblem(problem) { }
	virtual ~AiAlgorithm() { };

public slots:
	virtual AiNode run() = 0;

protected slots:
	virtual bool isFoundGoal(AiNode& node) { return node == mProblem->mGoal; };
	virtual void open(AiNode&) = 0;
	virtual int getCostOfGoingTo(const AiState&) const = 0;

protected:
	QVector<AiNode> mSetOfOpenNodes;
	QMap<AiNode, int> mPriorityQueue;
	AiProblem *mProblem;
};

#endif // AIALGORITHM_H
