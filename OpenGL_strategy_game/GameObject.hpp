#include<string>
#include<map>

#include"ResourceManager.hpp"
typedef const std::string URI;

template <class Resource> class GameObject {
public:
	GameObject(string id, URI& source, ResourceManager& rm);
	~GameObject() { rm.Unload(source); }
private:
	typedef std::pair<URI, Resource*> ResourcePair;
	typedef std::map<URI, Resource*> ResourceList;
	ResourceList Resources;
};