#ifndef RRMAGNOBOT_GAZEBO_FORCE_PLUGIN_HPP_
#define RRMAGNOBOT_GAZEBO_FORCE_PLUGIN_HPP_

#include <gazebo/common/Time.hh>
#include <gazebo/physics/Joint.hh>
#include <gazebo/physics/Link.hh>
#include <gazebo/physics/Model.hh>
#include <gazebo/physics/World.hh>
#include <gazebo/common/Plugin.hh>
#include <sdf/sdf.hh>
#include <unistd.h>

#include "rclcpp/rclcpp.hpp"


namespace rrmagnobot_gazebo_force
{
    class RRMagnobotGazeboForcePlugin : public gazebo::ModelPlugin
    {
    public:
        RRMagnobotGazeboForcePlugin();

        ~RRMagnobotGazeboForcePlugin() = default;

    protected:

        void Load(gazebo::physics::ModelPtr _model, sdf::ElementPtr _sdf) override;

        void OnUpdate();

    private:
        gazebo::physics::ModelPtr model;
        gazebo::event::ConnectionPtr updateConnection;
    };
}

#endif  // RRMAGNOBOT_GAZEBO_FORCE_PLUGIN_HPP_