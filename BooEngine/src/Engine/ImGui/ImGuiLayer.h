#pragma once

#include "Engine/Layers/Layer.h"

#include "Engine/Events/AppEvent.h"
#include "Engine/Events/KeyEvent.h"
#include "Engine/Events/MouseEvent.h"

namespace boo {

	class BOO_API ImGuiLayer : public Layer
	{
    private:
        float m_Time = 0.0f;

	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
        virtual void OnImGuiRender() override;

        void Begin();
        void End();

	};

}