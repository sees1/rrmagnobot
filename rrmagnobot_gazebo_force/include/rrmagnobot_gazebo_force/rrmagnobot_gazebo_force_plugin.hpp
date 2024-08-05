#ifndef RRMAGNOBOT_GAZEBO_FORCE_PLUGIN_HPP_
#define RRMAGNOBOT_GAZEBO_FORCE_PLUGIN_HPP_

#include <gazebo/gazebo.hh>
#include <gazebo/common/CommonTypes.hh>
#include <gazebo/physics/physics.hh>

namespace rrmagnobot_gazebo_force
{
    class RRMagnobotGazeboForcePlugin : public gazebo::ModelPlugin
    {
    public:
        RRMagnobotGazeboForcePlugin() = default;

        ~RRMagnobotGazeboForcePlugin() = default;

        void Load(gazebo::physics::ModelPtr _model, sdf::ElementPtr _sdf) override;

        void OnUpdate();

    private:
        gazebo::physics::ModelPtr model;
        gazebo::event::ConnectionPtr updateConnection;
    };
}

#endif  // RRMAGNOBOT_GAZEBO_FORCE_PLUGIN_HPP_