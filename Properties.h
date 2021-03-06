#ifndef PROPERTIES_H
#define PROPERTIES_H
class Properties
{

protected:
    QMap<QString, QVariant> _hive;
    template<typename T>
    void set(const QString& name, const T& value)
    {
        _hive[name] = value;
    }

    template<typename T>
    const T get(const QString& name) const
    {
        return qvariant_cast<T>(_hive[name]);
    }

    template<typename T>
    const T get(const QString& name, const T& def) const
    {
        return _hive.contains(name) ? get(name) : def;
    }
public:
    Properties()
    {

    }

    Properties(const Properties& other)
    {
        *this = other;
    }

    virtual ~Properties()
    {

    }
};

#define PROPERTY(TYPE, NAME, ...) \
    void NAME(const TYPE& value){ set<TYPE>(#NAME, value); } \
    TYPE NAME() const { return get<TYPE>(#NAME); }

#endif // PROPERTIES_H
