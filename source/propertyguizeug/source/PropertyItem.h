
#pragma once

#include <QList>

#include <signalzeug/ScopedConnection.h>


namespace reflectionzeug
{
    class AbstractProperty;
    class AbstractValueProperty;
    class PropertyGroup;
}

namespace propertyguizeug
{

class PropertyItem
{
public:
    PropertyItem(reflectionzeug::AbstractProperty * collection,
                 PropertyModel * model);

    PropertyItem(reflectionzeug::AbstractValueProperty * property,
                 PropertyModel * model);

    PropertyItem(reflectionzeug::PropertyGroup * group,
                 PropertyModel * model);

    ~PropertyItem();

    reflectionzeug::AbstractProperty * property() const;

    PropertyItem * parent() const;
    void setParent(PropertyItem * parent);
    bool hasParent() const;

    bool hasChildren() const;
    size_t childCount() const;

    PropertyItem * at(size_t i) const;

    int indexOf(PropertyItem * item) const;

    void insertChild(size_t i, PropertyItem * item);
    bool removeChild(size_t i);

    void appendChild(PropertyItem * item);

private:
    reflectionzeug::AbstractProperty * m_property;

    PropertyItem * m_parent;
    QList<PropertyItem *> m_children;

    QList<signalzeug::ScopedConnection> m_connections;
};

} // namespace propertyguizeug
