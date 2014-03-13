
#pragma once

#include <QWidget>

#include <propertyguizeug/propertyguizeug.h>


class QBoxLayout;

namespace propertyguizeug
{

class PropertyEditor : public QWidget
{
public:
	static const int s_horizontalMargin = 3;
	static const int s_spacing = 3;

public:
	PropertyEditor(QWidget * parent = nullptr);
	virtual ~PropertyEditor();

	virtual void childEvent(QChildEvent * event);
    virtual bool eventFilter(QObject * object, QEvent * event);

protected:
	QBoxLayout * boxLayout() const;
	
	QBoxLayout * m_layout;

};

} // namespace propertyguizeug