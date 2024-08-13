#include <rrmagnobot_gazebo_force/rrmagnobot_gazebo_force_plugin.hpp>


namespace rrmagnobot_gazebo_force
{

  RRMagnobotGazeboForcePlugin::RRMagnobotGazeboForcePlugin(){}

  void RRMagnobotGazeboForcePlugin::Load(gazebo::physics::ModelPtr _model, sdf::ElementPtr _sdf)
  {
    RCLCPP_INFO_STREAM(
    rclcpp::get_logger("rrmagnobot_plugin"),
    "Loading rrmagnobot_gazebo_force plugin");


    if (_model->GetName() == "rrmagnobot")
    {
      this->model = _model;
      this->updateConnection = gazebo::event::Events::ConnectWorldUpdateBegin(
          std::bind(&RRMagnobotGazeboForcePlugin::OnUpdate, this));
    }
  }

  void RRMagnobotGazeboForcePlugin::OnUpdate()
  {
    ignition::math::Vector3d force(0, 0, -100);
    this->model->GetLink("body_link")->AddRelativeForce(force);
  }

  GZ_REGISTER_MODEL_PLUGIN(RRMagnobotGazeboForcePlugin)

}