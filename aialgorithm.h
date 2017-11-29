#ifndef AIALGORITHM_H
#define AIALGORITHM_H

#include <QObject>

class AiAlgorithm : public QObject
{
	Q_OBJECT

public:
	AiAlgorithm(QObject *parent = 0);
	virtual ~AiAlgorithm() { }

	virtual int func() = 0;

protected:

};

#endif // AIALGORITHM_H
