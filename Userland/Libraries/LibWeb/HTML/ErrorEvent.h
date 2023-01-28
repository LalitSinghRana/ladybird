/*
 * Copyright (c) 2021, Luke Wilde <lukew@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibWeb/DOM/Event.h>

namespace Web::HTML {

// https://html.spec.whatwg.org/multipage/webappapis.html#erroreventinit
struct ErrorEventInit : public DOM::EventInit {
    DeprecatedString message { "" };
    DeprecatedString filename { "" }; // FIXME: This should be a USVString.
    u32 lineno { 0 };
    u32 colno { 0 };
    JS::Value error { JS::js_null() };
};

// https://html.spec.whatwg.org/multipage/webappapis.html#errorevent
class ErrorEvent final : public DOM::Event {
    WEB_PLATFORM_OBJECT(ErrorEvent, DOM::Event);

public:
    static ErrorEvent* create(JS::Realm&, DeprecatedFlyString const& event_name, ErrorEventInit const& event_init = {});
    static ErrorEvent* construct_impl(JS::Realm&, DeprecatedFlyString const& event_name, ErrorEventInit const& event_init);

    virtual ~ErrorEvent() override;

    // https://html.spec.whatwg.org/multipage/webappapis.html#dom-errorevent-message
    DeprecatedString const& message() const { return m_message; }

    // https://html.spec.whatwg.org/multipage/webappapis.html#dom-errorevent-filename
    DeprecatedString const& filename() const { return m_filename; }

    // https://html.spec.whatwg.org/multipage/webappapis.html#dom-errorevent-lineno
    u32 lineno() const { return m_lineno; }

    // https://html.spec.whatwg.org/multipage/webappapis.html#dom-errorevent-colno
    u32 colno() const { return m_colno; }

    // https://html.spec.whatwg.org/multipage/webappapis.html#dom-errorevent-error
    JS::Value error() const { return m_error; }

private:
    ErrorEvent(JS::Realm&, DeprecatedFlyString const& event_name, ErrorEventInit const& event_init);

    virtual JS::ThrowCompletionOr<void> initialize(JS::Realm&) override;
    virtual void visit_edges(Cell::Visitor&) override;

    DeprecatedString m_message { "" };
    DeprecatedString m_filename { "" }; // FIXME: This should be a USVString.
    u32 m_lineno { 0 };
    u32 m_colno { 0 };
    JS::Value m_error;
};

}
