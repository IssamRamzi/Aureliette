#include "GameObject.hpp"

GameObject::GameObject(vec3_f position, vec3_f scale, vec3_f rotation) : m_position(position), m_scale(scale), m_rotation(rotation), m_mesh(nullptr) {

}   

GameObject::GameObject(vec3_f position, vec3_f scale, vec3_f rotation, Mesh *mesh) :  m_position(position), m_scale(scale), m_rotation(rotation), m_mesh(mesh) {

}

mat4_f GameObject::GetModelMatrix(){

}

void GameObject::Draw(){

}

void GameObject::Update(){

}