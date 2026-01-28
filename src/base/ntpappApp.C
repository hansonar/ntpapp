#include "ntpappApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
ntpappApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

ntpappApp::ntpappApp(const InputParameters & parameters) : MooseApp(parameters)
{
  ntpappApp::registerAll(_factory, _action_factory, _syntax);
}

ntpappApp::~ntpappApp() {}

void
ntpappApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<ntpappApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"ntpappApp"});
  Registry::registerActionsTo(af, {"ntpappApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
ntpappApp::registerApps()
{
  registerApp(ntpappApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
ntpappApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ntpappApp::registerAll(f, af, s);
}
extern "C" void
ntpappApp__registerApps()
{
  ntpappApp::registerApps();
}
