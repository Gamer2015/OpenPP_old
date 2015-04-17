namespace Openpp {
namespace Objects {
namespace SDL2 {

template <typename T>
Sprite<T>::Sprite(OObject* const _pParent) :
	SDL_Rectangle<T>(_pParent)
{ }

template <typename T>
void Sprite<T>::set(const std::shared_ptr<SDL_Texture> pTexture)
{
	mpTexture = pTexture;
}
template <typename T>
void Sprite<T>::set(const std::string& Path)
{
    mpTexture = Texture::Get(Path).texture;
}

template <typename T>
std::shared_ptr<SDL_Texture> Sprite<T>::operator()() const
{
	return mpTexture;
}

template <typename T>
void Sprite<T>::Render() const
{
	if(mpTexture != nullptr)
        SDL_RenderCopyEx( Globals::Renderer(), mpTexture.get(), NULL, &(this->rect()), 180 / M_PI * (this->angle), &(this->rectOrigin()), SDL_FLIP_NONE);
}

} // SDL2

} // Objects
} // Openpp
