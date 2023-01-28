/*
 * Copyright (c) 2020, the SerenityOS developers.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibWeb/Bindings/Intrinsics.h>
#include <LibWeb/HTML/HTMLOptGroupElement.h>

namespace Web::HTML {

HTMLOptGroupElement::HTMLOptGroupElement(DOM::Document& document, DOM::QualifiedName qualified_name)
    : HTMLElement(document, move(qualified_name))
{
}

HTMLOptGroupElement::~HTMLOptGroupElement() = default;

JS::ThrowCompletionOr<void> HTMLOptGroupElement::initialize(JS::Realm& realm)
{
    MUST_OR_THROW_OOM(Base::initialize(realm));
    set_prototype(&Bindings::ensure_web_prototype<Bindings::HTMLOptGroupElementPrototype>(realm, "HTMLOptGroupElement"));

    return {};
}

}
