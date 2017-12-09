#ifndef MAPINTERFACE_H
#define MAPINTERFACE_H

#include <QQmlListProperty>

#include "map_objects/tile_map_object.h"

namespace game
{

class controller;

class qml_map_interface : public QObject
{
    Q_OBJECT

public:
    qml_map_interface( controller& controller, QObject* parent = nullptr );

    ~qml_map_interface(){}

    int get_rows_count() const noexcept;
    int get_columns_count() const noexcept;

    int get_tile_width() const noexcept;
    int get_tile_height() const noexcept;

    QQmlListProperty< tile_map_object > get_tiles();

    Q_PROPERTY( QQmlListProperty< game::tile_map_object > tiles READ get_tiles NOTIFY tiles_changed )
    Q_PROPERTY( int rows_num READ get_rows_count CONSTANT )
    Q_PROPERTY( int columns_num READ get_columns_count CONSTANT )
    Q_PROPERTY( int tile_width READ get_tile_width CONSTANT )
    Q_PROPERTY( int tile_height READ get_tile_height CONSTANT )

signals:
    void tiles_changed( QQmlListProperty< tile_map_object > );

private:
    controller& m_controller;
};

}// game

#endif // MAPINTERFACE_H