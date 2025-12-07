//
// Created by issbe on 27/09/2025.
//

#ifndef IBUFFER_H
#define IBUFFER_H
class iBuffer {
protected:
    unsigned int m_bufferID;
public:
    virtual void Bind() = 0;
    virtual void Unbind() = 0;
};
#endif //IBUFFER_H
