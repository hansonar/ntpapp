//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "ntpappTestApp.h"
#include "ntpappApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
ntpappTestApp::validParams()
{
  InputParameters params = ntpappApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

ntpappTestApp::ntpappTestApp(const InputParameters & parameters) : MooseApp(parameters)
{
  ntpappTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

ntpappTestApp::~ntpappTestApp() {}

void
ntpappTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  ntpappApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"ntpappTestApp"});
    Registry::registerActionsTo(af, {"ntpappTestApp"});
  }
}

void
ntpappTestApp::registerApps()
{
  registerApp(ntpappApp);
  registerApp(ntpappTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
ntpappTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ntpappTestApp::registerAll(f, af, s);
}
extern "C" void
ntpappTestApp__registerApps()
{
  ntpappTestApp::registerApps();
}
