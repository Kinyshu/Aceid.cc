#pragma once

#ifndef IMAGES_HPP
#define IMAGES_HPP

#define STB_IMAGE_IMPLEMENTATION
#include "../../../include/stb/stb_image.hpp"

class CImagesManager {
public:

    CImagesManager() { }
    ~CImagesManager() { }

    void init(ID3D11Device* d) {

        this->device = d;

        this->path("__HEADER__", "C:\\Aceid.cc\\assets\\images\\Ocean.jpg", 1920, 35);

        this->path("Weapon.Bullet", "C:\\Aceid.cc\\assets\\images\\icons\\w_bullet.png", 512, 512);
        this->path("Weapon.Crosshair", "C:\\Aceid.cc\\assets\\images\\icons\\w_crosshair.png", 512, 512);
        this->path("Weapon.Knife", "C:\\Aceid.cc\\assets\\images\\icons\\w_knife.png", 512, 512);

        this->path("Player.Movement", "C:\\Aceid.cc\\assets\\images\\icons\\p_movement.png", 512, 512);
        this->path("Player.ServerMovement", "C:\\Aceid.cc\\assets\\images\\icons\\p_server_movement.png", 512, 512);

        this->path("Visuals.Pov", "C:\\Aceid.cc\\assets\\images\\icons\\v_pov.png", 512, 512);
        this->path("Visuals.Environment", "C:\\Aceid.cc\\assets\\images\\icons\\v_environment.png", 512, 512);
        //
        this->path("Aiming.Pvp", "C:\\Aceid.cc\\assets\\images\\icons\\a_pvp.png", 512, 512);
        this->path("Aiming.Pve", "C:\\Aceid.cc\\assets\\images\\icons\\a_pve.png", 512, 512);
        this->path("Aiming.Trigger", "C:\\Aceid.cc\\assets\\images\\icons\\a_triggerbot.png", 512, 512);

        //
        this->path("Misc.Modules", "C:\\Aceid.cc\\assets\\images\\icons\\misc_functor.png", 512, 512);

        //
        this->path("Scripts.Lua", "C:\\Aceid.cc\\assets\\images\\icons\\scripts_lua.png", 512, 512);
        this->path("Scripts.Python", "C:\\Aceid.cc\\assets\\images\\icons\\scripts_python.png", 512, 512);

        //
        this->path("Settings.Global", "C:\\Aceid.cc\\assets\\images\\icons\\s_global.png", 512, 512);
        this->path("Settings.Brush", "C:\\Aceid.cc\\assets\\images\\icons\\s_brush.png", 512, 512);
        this->path("Settings.Config", "C:\\Aceid.cc\\assets\\images\\icons\\s_config.png", 512, 512);

        this->path("Account.Image", "C:\\Aceid.cc\\assets\\images\\Account.Image.jpg", 958, 960);
    }

    ID3D11ShaderResourceView* get(std::string name) {
        return this->images.find(name)->second;
    }

    void remove(std::string name) {
        this->images.erase(name);
    }

    void update(std::string name, std::string path, int w = 1920, int h = 35) {
        this->remove(name);
        this->path(name, path, w, h);
    }

private:
	ID3D11Device* device;
	std::map< std::string, ID3D11ShaderResourceView* > images;

protected:

    void path(std::string name, std::string path, int width, int height) {

        int x, y;
        byte* data = stbi_load(path.c_str(), &x, &y, 0, 4);
        if (data == 0)
            return;

        this->create(name, data, width, height);
    }

    void bytes(std::string name, byte* bytes, int size, int width, int height) {

        int x, y;
        byte* data = stbi_load_from_memory(bytes, size, &x, &y, 0, 4);
        if (data == 0)
            return;

        this->create(name, data, width, height);
    }

	void create(std::string name, byte* bytes, int width, int height) {

        ID3D11Texture2D* texture = nullptr;

        D3D11_TEXTURE2D_DESC desc;
        memset(&desc, 0, sizeof desc);
        {
            desc.Width = width;
            desc.Height = height;
            desc.MipLevels = 1;
            desc.ArraySize = 1;
            desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
            desc.SampleDesc.Count = 1;
            desc.Usage = D3D11_USAGE_DEFAULT;
            desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
            desc.CPUAccessFlags = 0;
        }

        D3D11_SUBRESOURCE_DATA subResource;
        {
            subResource.pSysMem = bytes;
            subResource.SysMemPitch = desc.Width * 4;
            subResource.SysMemSlicePitch = 0;
        }
        this->device->CreateTexture2D(&desc, &subResource, &texture);

        D3D11_SHADER_RESOURCE_VIEW_DESC viewDesc;
        memset(&viewDesc, 0, sizeof viewDesc);
        {
            viewDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
            viewDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
            viewDesc.Texture2D.MipLevels = desc.MipLevels;
            viewDesc.Texture2D.MostDetailedMip = 0;
        }

        ID3D11ShaderResourceView* shader = nullptr;

        this->device->CreateShaderResourceView(texture, &viewDesc, &shader);
        this->images.insert(std::pair(name, shader));

        texture->Release();
	}
};

#endif // !IMAGES_HPP