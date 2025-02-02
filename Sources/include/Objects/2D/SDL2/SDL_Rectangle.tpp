namespace Openpp {
namespace Objects {
namespace SDL2 {

template <typename T>
SDL_Rectangle<T>::SDL_Rectangle(OObject* const _pParent) :
	Rectangle<T>(_pParent)
{ }

template <typename T>
const SDL_Rect& SDL_Rectangle<T>::rect() const
{
	return mRect;
}
template <typename T>
const SDL_Point& SDL_Rectangle<T>::rectOrigin() const
{
	return mRectOrigin;
}
template <typename T>
bool SDL_Rectangle<T>::isInside(T X, T Y) const
{
	Vector2<float> mouse(X, Y);
	Vector2<float> origin(rect().x + rectOrigin().x, rect().y + rectOrigin().y);

	mouse -= origin;
	mouse.angle -= this->angle;
	mouse += origin;

	if(mouse.x < rect().x)
		return false;
	if(mouse.x > rect().x + rect().w)
		return false;

	if(mouse.y < rect().y)
		return false;
	if(mouse.y > rect().y + rect().h)
		return false;

	return true;
}

template <typename T>
void SDL_Rectangle<T>::ChildChanged(int _childId)
{
	Rectangle<T>::ChildChanged();

	if(_childId != Rectangle<T>::angle.id());
	{
        mRect.w = this->size.x;
        mRect.h = this->size.y;

        mRectOrigin.x = ceil(mRect.w / 2.0 * (this->origin.x + 1));
        mRectOrigin.y = ceil(mRect.h / 2.0 * (this->origin.y + 1));

        mRect.x = this->position.x - mRectOrigin.x;
        mRect.y = this->position.y - mRectOrigin.y;
	}
}

} // SDL2
} // Objects
} // Openpp
