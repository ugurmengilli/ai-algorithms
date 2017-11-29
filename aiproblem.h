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
	AiProblem(QObject *parent = 0);
	virtual ~AiProblem() { }

public slots:
	virtual void getSuccessors(QVector<AiState>& successors) const = 0;

protected:
	AiState mCurrentState;
	AiState mStart;
	AiState mGoal;
};

#endif // AIPROBLEM_H
