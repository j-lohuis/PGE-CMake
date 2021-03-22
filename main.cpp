#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

// Override base class with your custom functionality
class Starfield : public olc::PixelGameEngine
{
public:
    Starfield()
    {
        sAppName = "Starfield";
    }

    const int nStars = 1000;

    struct sStar
    {
        float fAngle = 0.0f;
        float fDistance = 0.0f;
        float fSpeed = 0.0f;
        olc::Pixel col = olc::WHITE;
    };

    std::vector<sStar> vStars;
    olc::vf2d vOrigin;

    olc::Renderable rApple;

public:

    float Random(float a, float b)
    {
        return (b - a) * (float(rand()) / float(RAND_MAX)) + a;
    }

    bool OnUserCreate() override
    {
        vStars.resize(nStars);

        // Initial stars
        for (auto& star : vStars)
        {
            star.fAngle = Random(0.0f, 2.0f * 3.14159f);
            star.fSpeed = Random(10.0f, 100.0f);
            star.fDistance = Random(20.0f, 200.0f);
            float lum = Random (0.3f, 1.0f);
            star.col = olc::PixelF(lum, lum, lum, 1.0f);
        }

        vOrigin = { float(ScreenWidth() / 2), float(ScreenHeight() / 2) };

        rApple.Load("assets/apple.png");

        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override
    {
        Clear(olc::BLACK);

        // Update Stars & Draw
        for (auto& star : vStars)
        {
            star.fDistance += star.fSpeed * fElapsedTime * (star.fDistance / 100.0f);
            if (star.fDistance > 200.0f)
            {
                star.fAngle = Random(0.0f, 2.0f * 3.14159f);
                star.fSpeed = Random(10.0f, 100.0f);
                star.fDistance = Random(20.0f, 200.0f);
                float lum = Random (0.3f, 1.0f);
                star.col = olc::PixelF(lum, lum, lum, 1.0f);
            }

            Draw(olc::vf2d(cos(star.fAngle), sin(star.fAngle)) * star.fDistance + vOrigin, star.col * (star.fDistance / 100.0f));
        }

        DrawDecal(GetMousePos(), rApple.Decal());

        return true;
    }
};

int main()
{
    Starfield demo;
    if (demo.Construct(256, 240, 4, 4))
        demo.Start();
    return 0;
}
