#ifndef SYSTEMS_H
#define SYSTEMS_H

#include "events.h"
#include "components.h"
#include "framework/world.h"

namespace game
{

namespace systems
{

class health_system : public ecs::system
{
public:
    health_system( ecs::world& world ) : ecs::system( world ){}

    void tick() override
    {
        events::entity_killed killed_event;

        m_world.for_each< component::health >(
            []( ecs::entity& entity, component::health& health )
            {
                if( !health.alive() )
                {
                    m_world.emit_event(  )
                }
            } );
    }
};

}// systems

}// ecs

#endif
