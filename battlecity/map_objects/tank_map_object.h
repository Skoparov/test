#ifndef TANK_MAP_OBJECT_H
#define TANK_MAP_OBJECT_H

#include "graphics_map_object.h"
#include "movable_map_object.h"

#include "ecs/general_enums.h"

namespace game
{

class tank_map_object : public movable_map_object
{
    Q_OBJECT

public:
    tank_map_object() = default;
    tank_map_object( ecs::entity* entity, const object_type& type, QObject* parent = nullptr );

    bool set_fired( bool fired ) noexcept;
    bool get_fired() const noexcept;

    Q_PROPERTY( bool fired READ get_fired WRITE set_fired )
};

}// game

#endif
