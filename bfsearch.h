#ifndef BFSEARCH_H
#define BFSEARCH_H

#include <QObject>
#include "aialgorithm.h"

class BFSearch : public AiAlgorithm, public QObject
{
	Q_OBJECT

	enum BFStype {
		UniformCost,
		LeastCost
	};

public:
	BFSearch(AiProblem *problem, QObject *parent = 0);
	BFSearch(AiProblem *problem, BFStype type, QObject *parent = 0);
	~BFSearch() override;

public slots:
	/// <summary> Runs the algorithm on the given problem. </summary>
	/// <return> Starting node of the problem pointing the next node on the path to the goal </return>
	AiNode run() override;
	/// <summary> Gets the cost of going to the given state from the current node </summary>
	/// <param name='nextState'> One of the next possible state of the current node. </param name>
	/// <return> Cost of going to the state </return>
	int getCostOfGoingTo(AiState &nextState) const override;

protected:
	void open(AiNode &node) override;

private:
	const int mUniformCost = 1;
	BFStype mSearchType;
};

#endif // BFSEARCH_H
