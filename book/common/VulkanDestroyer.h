//
// Created by aicdg on 2017/6/14.
//

//
// VulkanDestroyer

#ifndef VKCOOKBOOK_VULKANDESTROYER_H
#define VKCOOKBOOK_VULKANDESTROYER_H


#include <utility>
#include <vector>
#include "VulkanFunctions.h"

namespace VKCookbook {

    // Wrapper for automatic object destruction

    template <class OBJ>
    class VkDestroyer {
    public:
        VkDestroyer() :
                Device( VK_NULL_HANDLE ),
                Object( VK_NULL_HANDLE ) {
        }

        VkDestroyer( VkDevice device ) :
                Device( device ),
                Object( VK_NULL_HANDLE ) {
        }

        VkDestroyer( VkDestroyer<VkDevice> const & device ) :
                Device( *device ),
                Object( VK_NULL_HANDLE ) {
        }

        VkDestroyer( VkDevice device, OBJ object ) :
                Device( device ),
                Object( object ) {
        }

        VkDestroyer( VkDestroyer<VkDevice> const & device, OBJ object ) :
                Device( *device ),
                Object( object ) {
        }

        ~VkDestroyer() {
            if( (VK_NULL_HANDLE != Device) &&
                (VK_NULL_HANDLE != Object) ) {
                Destroy();
            }
        }

        VkDestroyer( VkDestroyer<OBJ> && other ) :
                VkDestroyer() {
            *this = std::move( other );
        }

        VkDestroyer& operator=( VkDestroyer<OBJ> && other ) {
            if( this != &other ) {
                VkDevice  device = Device;
                OBJ       object = Object;
                Device = other.Device;
                Object = other.Object;
                other.Device = device;
                other.Object = object;
            }
            return *this;
        }

        OBJ & Get() {
            return Object;
        }

        OBJ * GetPtr() {
            return &Object;
        }

        OBJ & operator*() {
            return Object;
        }

        OBJ const & operator*() const {
            return Object;
        }

        bool operator !() const {
            return VK_NULL_HANDLE == Object;
        }

        explicit operator bool() const {
            return VK_NULL_HANDLE != Object;
        }

    private:
        VkDestroyer( VkDestroyer<OBJ> const & );
        VkDestroyer& operator=( VkDestroyer<OBJ> const & );
        void Destroy();

        VkDevice  Device;
        OBJ       Object;
    };

    // VkInstance specialization for VkDestroyer

    template <>
    class VkDestroyer<VkInstance> {
    public:
        VkDestroyer() :
                Instance( VK_NULL_HANDLE ) {
        }

        VkDestroyer( VkInstance object ) :
                Instance( object ) {
        }

        ~VkDestroyer() {
            if( (VK_NULL_HANDLE != Instance) ) {
                Destroy();
            }
        }

        VkDestroyer( VkDestroyer<VkInstance> && other ) {
            *this = std::move( other );
        }

        VkDestroyer& operator=( VkDestroyer<VkInstance> && other ) {
            if( this != &other ) {
                Instance = other.Instance;
                other.Instance = VK_NULL_HANDLE;
            }
            return *this;
        }

        VkInstance & Get() {
            return Instance;
        }

        VkInstance * GetPtr() {
            return &Instance;
        }

        VkInstance & operator*() {
            return Instance;
        }

        VkInstance const & operator*() const {
            return Instance;
        }

        bool operator !() const {
            return VK_NULL_HANDLE == Instance;
        }

        explicit operator bool() const {
            return VK_NULL_HANDLE != Instance;
        }

    private:
        VkDestroyer( VkDestroyer<VkInstance> const & );
        VkDestroyer& operator=( VkDestroyer<VkInstance> const & );
        void Destroy();

        VkInstance  Instance;
    };

    // VkDevice specialization for VkDestroyer

    template <>
    class VkDestroyer<VkDevice> {
    public:
        VkDestroyer() :
                LogicalDevice( VK_NULL_HANDLE ) {
        }

        VkDestroyer( VkDevice object ) :
                LogicalDevice( object ) {
        }

        ~VkDestroyer() {
            if( (VK_NULL_HANDLE != LogicalDevice) ) {
                Destroy();
            }
        }

        VkDestroyer( VkDestroyer<VkDevice> && other ) {
            *this = std::move( other );
        }

        VkDestroyer& operator=( VkDestroyer<VkDevice> && other ) {
            if( this != &other ) {
                LogicalDevice = other.LogicalDevice;
                other.LogicalDevice = VK_NULL_HANDLE;
            }
            return *this;
        }

        VkDevice & Get() {
            return LogicalDevice;
        }

        VkDevice * GetPtr() {
            return &LogicalDevice;
        }

        VkDevice & operator*() {
            return LogicalDevice;
        }

        VkDevice const & operator*() const {
            return LogicalDevice;
        }

        bool operator !() const {
            return VK_NULL_HANDLE == LogicalDevice;
        }

        explicit operator bool() const {
            return VK_NULL_HANDLE != LogicalDevice;
        }

    private:
        VkDestroyer( VkDestroyer<VkDevice> const & );
        VkDestroyer& operator=( VkDestroyer<VkDevice> const & );
        void Destroy();

        VkDevice LogicalDevice;
    };

    // VkSurfaceKHR specialization for VkDestroyer

    template <>
    class VkDestroyer<VkSurfaceKHR> {
    public:
        VkDestroyer() :
                Instance( VK_NULL_HANDLE ),
                Object( VK_NULL_HANDLE ) {
        }

        VkDestroyer( VkInstance instance ) :
                Instance( instance ),
                Object( VK_NULL_HANDLE ) {
        }

        VkDestroyer( VkDestroyer<VkInstance> const & instance ) :
                Instance( *instance ),
                Object( VK_NULL_HANDLE ) {
        }

        VkDestroyer( VkInstance instance, VkSurfaceKHR object ) :
                Instance( instance ),
                Object( object ) {
        }

        VkDestroyer( VkDestroyer<VkInstance> const & instance, VkSurfaceKHR object ) :
                Instance( *instance ),
                Object( object ) {
        }

        ~VkDestroyer() {
            if( (VK_NULL_HANDLE != Instance) &&
                (VK_NULL_HANDLE != Object) ) {
                Destroy();
            }
        }

        VkDestroyer( VkDestroyer<VkSurfaceKHR> && other ) {
            *this = std::move( other );
        }

        VkDestroyer& operator=( VkDestroyer<VkSurfaceKHR> && other ) {
            if( this != &other ) {
                Instance = other.Instance;
                Object = other.Object;
                other.Instance = VK_NULL_HANDLE;
                other.Object = VK_NULL_HANDLE;
            }
            return *this;
        }

        VkSurfaceKHR & Get() {
            return Object;
        }

        VkSurfaceKHR * GetPtr() {
            return &Object;
        }

        VkSurfaceKHR & operator*() {
            return Object;
        }

        VkSurfaceKHR const & operator*() const {
            return Object;
        }

        bool operator !() const {
            return VK_NULL_HANDLE == Object;
        }

        explicit operator bool() const {
            return VK_NULL_HANDLE != Object;
        }

    private:
        VkDestroyer( VkDestroyer<VkSurfaceKHR> const & );
        VkDestroyer& operator=( VkDestroyer<VkSurfaceKHR> const & );
        void Destroy();

        VkInstance    Instance;
        VkSurfaceKHR  Object;
    };

    template <class PARENT, class OBJ>
    void InitVkDestroyer( PARENT const & parent, OBJ obj, VkDestroyer<OBJ> & wrapper ) {
        wrapper = VkDestroyer<OBJ>( parent, obj );
    }

    template <class PARENT, class OBJ>
    void InitVkDestroyer( PARENT const & parent, VkDestroyer<OBJ> & wrapper ) {
        wrapper = VkDestroyer<OBJ>( parent );
    }

};


#endif //VKCOOKBOOK_VULKANDESTROYER_H
