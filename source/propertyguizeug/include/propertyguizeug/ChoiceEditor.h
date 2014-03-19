
#pragma once

#include <propertyguizeug/PropertyEditor.h>

namespace reflectionzeug {
    template <typename Type>
    class Property;
}

namespace propertyguizeug
{

class PROPERTYGUIZEUG_API ChoiceEditor : public PropertyEditor
{
public:
    ChoiceEditor(reflectionzeug::Property<std::string> * property, QWidget * parent = nullptr);
    virtual ~ChoiceEditor();
    
    void setString(const QString & text);

protected:
    reflectionzeug::Property<std::string> * m_property;
};

} // namespace propertyguizeug