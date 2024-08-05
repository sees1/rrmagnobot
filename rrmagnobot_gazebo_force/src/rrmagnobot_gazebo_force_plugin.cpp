#include <rrmagnobot_gazebo_force/rrmagnobot_gazebo_force_plugin.hpp>

namespace rrmagnobot_gazebo_force
{

  void RRMagnobotGazeboForcePlugin::Load(gazebo::physics::ModelPtr _model, sdf::ElementPtr _sdf)
  {
    if (_model->GetName() == "rrmagnobot")
    {
      this->model = _model;
      this->updateConnection = gazebo::event::Events::ConnectWorldUpdateBegin(
          std::bind(&RRMagnobotGazeboForcePlugin::OnUpdate, this));
    }
  }

  void RRMagnobotGazeboForcePlugin::OnUpdate()
  {
    ignition::math::Vector3d force(0, 0, -1000000);
    this->model->GetLink("body_link")->SetForce(force);
  }

}