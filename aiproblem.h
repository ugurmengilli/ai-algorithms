#ifndef AIPROBLEM_H
#define AIPROBLEM_H

#include <QObject>
#include <QList>
#include <QVector>

typedef QList<int> AiState;

class AiProblem : public QObject
{
	friend class AiAlgorithm;

	Q_OBJECT

public:
	AiProblem(QObject *parent = 0) : QObject(parent) { };
	virtual ~AiProblem() { }

public slots:
	virtual const AiState& getCurrentState() const = 0;
	virtual void getSuccessors(QVector<AiState>& successors) const = 0;
	virtual bool setCurrentState(AiState&) = 0;

protected:
	AiState mCurrentState;
	AiState mStart;
	AiState mGoal;
};

#endif // AIPROBLEM_H
