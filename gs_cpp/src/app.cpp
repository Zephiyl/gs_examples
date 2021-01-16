#define GS_IMPL
#define GS_NO_HIJACK_MAIN
#include <gs/gs.h>

#define GS_IMMEDIATE_DRAW_IMPL
#include <gs/util/gs_idraw.h>

#define GS_ASSET_IMPL
#include <gs/util/gs_asset.h>

#include "app.h"

#include <iostream>

static void AppInit()
{
    App* app = gs_engine_user_data(App);
    app->m_gcb = gs_command_buffer_new();
    app->m_gsi = gs_immediate_draw_new();
    app->m_gsa = gs_asset_manager_new();
    app->Init();
}

static void AppUpdate()
{
    App* app = gs_engine_user_data(App);
    app->Update();
}

static void AppShutdown()
{
    App* app = gs_engine_user_data(App);
    app->Shutdown();
}

App::App() 
{
    m_app = {0};
    m_app.init = AppInit;
    m_app.update = AppUpdate;
    m_app.shutdown = AppShutdown;
    m_app.user_data = (void*)this;
}

App::~App() {
}

void App::Init()
{
    // Nothing by default...
}

void App::Update()
{
    // Nothing by default...
}

void App::Shutdown()
{
    // Nothing by default...
}

void App::LoadTexture(std::string name, std::string path, gs_graphics_texture_desc_t* desc) 
{
    m_assetTable[name] = gs_assets_load_from_file(&m_gsa, gs_asset_texture_t, path.c_str(), desc); 
}

void App::Run() 
{
    gs_engine_create(m_app)->run();
}
