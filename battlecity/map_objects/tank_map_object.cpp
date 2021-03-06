#include "tank_map_object.h"

#include <mutex>

#include "ecs/components.h"
#include "ecs/framework/details/rw_lock_guard.h"

namespace game
{

tank_map_object::tank_map_object( ecs::entity* entity, const object_type& type, QObject* parent ):
    movable_map_object( entity, type, parent )
{
    if( type != object_type::player_tank && type != object_type::enemy_tank )
    {
        throw std::invalid_argument{ "Invalid tank type" };
    }
}

bool tank_map_object::set_fired( bool fired ) noexcept
{
    component::turret_object& t = m_entity->get_component_unsafe< component::turret_object >();
    ecs::rw_lock_guard< ecs::rw_lock > l{ t, ecs::lock_mode::read };
    return t.set_fire_status( fired );
}

bool tank_map_object::get_fired() const noexcept
{
    component::turret_object& t = m_entity->get_component_unsafe< component::turret_object >();
    ecs::rw_lock_guard< ecs::rw_lock > l{ t, ecs::lock_mode::read };
    return t.has_fired();
}

}// game
