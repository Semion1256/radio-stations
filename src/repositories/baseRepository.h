#pragma once
#include <QVector>
template <typename T>
class BaseRepository{
public:
    virtual bool create(T& entity) = 0;
    virtual QVector<T> getAll() = 0;
    virtual T getById(int id) = 0;
    virtual bool update(const T& entity) = 0;
    virtual bool remove(int id) = 0;
    virtual ~BaseRepository() = default;

};
