/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */
#ifndef INCLUDED_SW_SOURCE_UI_DIALOG_SWDLGFACT_HXX
#define INCLUDED_SW_SOURCE_UI_DIALOG_SWDLGFACT_HXX

#include <swabstdlg.hxx>

class SwInsertAbstractDlg;
class SwAsciiFilterDlg;
class Dialog;
class SwBreakDlg;
class SwSortDlg;
class SwTableHeightDlg;
class SwTableWidthDlg;
class SwMergeTableDlg;
class SfxTabDialog;
class SwConvertTableDlg;
class SwInsertDBColAutoPilot;
class SwLabDlg;
class SwSelGlossaryDlg;
class SwAutoFormatDlg;
class SwFieldDlg;
class SwRenameXNamedDlg;
class SwModalRedlineAcceptDlg;
class SwTOXMark;
class SwSplitTableDlg;

#include <itabenum.hxx>
#include <boost/optional.hpp>
#include <o3tl/deleter.hxx>

namespace sw
{
class DropDownFieldDialog;
}

#define DECL_ABSTDLG_BASE(Class,DialogClass)        \
protected:                                          \
    ScopedVclPtr<DialogClass> pDlg;                 \
public:                                             \
    explicit        Class( DialogClass* p)          \
                     : pDlg(p)                      \
                     {}                             \
    virtual short   Execute() override;             \
    virtual bool    StartExecuteAsync(VclAbstractDialog::AsyncContext &rCtx) override;

#define IMPL_ABSTDLG_BASE(Class)                    \
short Class::Execute()                              \
{                                                   \
    return pDlg->Execute();                         \
}                                                   \
bool Class::StartExecuteAsync(VclAbstractDialog::AsyncContext &rCtx) \
{ \
    return pDlg->StartExecuteAsync(rCtx); \
}

class SwWordCountFloatDlg;
class AbstractSwWordCountFloatDlg_Impl : public AbstractSwWordCountFloatDlg
{
    DECL_ABSTDLG_BASE(AbstractSwWordCountFloatDlg_Impl,SwWordCountFloatDlg)
    virtual void                UpdateCounts() override;
    virtual void                SetCounts(const SwDocStat &rCurrCnt, const SwDocStat &rDocStat) override;
    virtual vcl::Window *            GetWindow() override; //this method is added for return a Window type pointer
};

class AbstractSwInsertAbstractDlg_Impl : public AbstractSwInsertAbstractDlg
{
    DECL_ABSTDLG_BASE(AbstractSwInsertAbstractDlg_Impl,SwInsertAbstractDlg)
    virtual sal_uInt8   GetLevel() const override ;
    virtual sal_uInt8   GetPara() const override ;
};

class SwAbstractSfxDialog_Impl :public SfxAbstractDialog
{
    DECL_ABSTDLG_BASE(SwAbstractSfxDialog_Impl,SfxModalDialog)
    virtual const SfxItemSet*   GetOutputItemSet() const override;
    virtual void        SetText( const OUString& rStr ) override;
};

class AbstractSwAsciiFilterDlg_Impl : public AbstractSwAsciiFilterDlg
{
protected:
    std::unique_ptr<SwAsciiFilterDlg> m_xDlg;
public:
    explicit AbstractSwAsciiFilterDlg_Impl(SwAsciiFilterDlg* p)
        : m_xDlg(p)
    {
    }
    virtual short Execute() override;
    virtual void FillOptions( SwAsciiOptions& rOptions ) override;
};

class VclAbstractDialog_Impl : public VclAbstractDialog
{
    DECL_ABSTDLG_BASE(VclAbstractDialog_Impl,Dialog)
};

class AbstractGenericDialog_Impl : public VclAbstractDialog
{
protected:
    std::unique_ptr<weld::GenericDialogController> m_xDlg;
public:
    explicit AbstractGenericDialog_Impl(weld::GenericDialogController* p)
        : m_xDlg(p)
    {
    }
    virtual short Execute() override;
};

class AbstractSwSortDlg_Impl : public VclAbstractDialog
{
protected:
    std::unique_ptr<SwSortDlg> m_xDlg;
public:
    explicit AbstractSwSortDlg_Impl(SwSortDlg* p)
        : m_xDlg(p)
    {
    }
    virtual short Execute() override;
};

class AbstractSwBreakDlg_Impl : public AbstractSwBreakDlg
{
protected:
    std::unique_ptr<SwBreakDlg> m_xDlg;
public:
    explicit AbstractSwBreakDlg_Impl(SwBreakDlg* p)
        : m_xDlg(p)
    {
    }
    virtual short Execute() override;
    virtual OUString                        GetTemplateName() override;
    virtual sal_uInt16                      GetKind() override;
    virtual ::boost::optional<sal_uInt16>   GetPageNumber() override;
};

class AbstractSwTableWidthDlg_Impl : public VclAbstractDialog
{
protected:
    std::unique_ptr<SwTableWidthDlg> m_xDlg;
public:
    explicit AbstractSwTableWidthDlg_Impl(SwTableWidthDlg* p)
        : m_xDlg(p)
    {
    }
    virtual short Execute() override;
};

class AbstractSwTableHeightDlg_Impl : public VclAbstractDialog
{
protected:
    std::unique_ptr<SwTableHeightDlg> m_xDlg;
public:
    explicit AbstractSwTableHeightDlg_Impl(SwTableHeightDlg* p)
        : m_xDlg(p)
    {
    }
    virtual short Execute() override;
};

class AbstractSwMergeTableDlg_Impl : public VclAbstractDialog
{
protected:
    std::unique_ptr<SwMergeTableDlg> m_xDlg;
public:
    explicit AbstractSwMergeTableDlg_Impl(SwMergeTableDlg* p)
        : m_xDlg(p)
    {
    }
    virtual short Execute() override;
};

class AbstractSplitTableDialog_Impl : public AbstractSplitTableDialog // add for
{
protected:
    std::unique_ptr<SwSplitTableDlg> m_xDlg;
public:
    explicit AbstractSplitTableDialog_Impl(SwSplitTableDlg* p)
        : m_xDlg(p)
    {
    }
    virtual short Execute() override;
    virtual SplitTable_HeadlineOption GetSplitMode() override;
};

class AbstractTabDialog_Impl : virtual public SfxAbstractTabDialog
{
    DECL_ABSTDLG_BASE( AbstractTabDialog_Impl,SfxTabDialog )
    virtual void                SetCurPageId( sal_uInt16 nId ) override;
    virtual void                SetCurPageId( const OString &rName ) override;
    virtual const SfxItemSet*   GetOutputItemSet() const override;
    virtual const sal_uInt16*       GetInputRanges( const SfxItemPool& pItem ) override;
    virtual void                SetInputSet( const SfxItemSet* pInSet ) override;
        //From class Window.
    virtual void        SetText( const OUString& rStr ) override;
};

class AbstractApplyTabDialog_Impl : public AbstractTabDialog_Impl, virtual public SfxAbstractApplyTabDialog
{
public:
    explicit AbstractApplyTabDialog_Impl( SfxTabDialog* p)
        : AbstractTabDialog_Impl(p)
    {
    }
    DECL_LINK(ApplyHdl, Button*, void);
private:
    Link<LinkParamNone*,void> m_aHandler;
    virtual void                SetApplyHdl( const Link<LinkParamNone*,void>& rLink ) override;
};

class AbstractSwConvertTableDlg_Impl :  public AbstractSwConvertTableDlg
{
protected:
    std::unique_ptr<SwConvertTableDlg> m_xDlg;
public:
    explicit AbstractSwConvertTableDlg_Impl(SwConvertTableDlg* p)
        : m_xDlg(p)
    {
    }
    virtual short Execute() override;
    virtual void GetValues( sal_Unicode& rDelim,SwInsertTableOptions& rInsTableFlags,
                    SwTableAutoFormat const*& prTAFormat) override;
};

class AbstractSwInsertDBColAutoPilot_Impl :  public AbstractSwInsertDBColAutoPilot
{
    DECL_ABSTDLG_BASE( AbstractSwInsertDBColAutoPilot_Impl,SwInsertDBColAutoPilot)
    virtual void DataToDoc( const css::uno::Sequence< css::uno::Any >& rSelection,
        css::uno::Reference< css::sdbc::XDataSource> rxSource,
        css::uno::Reference< css::sdbc::XConnection> xConnection,
        css::uno::Reference< css::sdbc::XResultSet > xResultSet) override;
};

class AbstractDropDownFieldDialog_Impl : public AbstractDropDownFieldDialog
{
    DECL_ABSTDLG_BASE(AbstractDropDownFieldDialog_Impl, sw::DropDownFieldDialog)
    virtual OString       GetWindowState() const override; //this method inherit from SystemWindow
    virtual void          SetWindowState( const OString& rStr ) override; //this method inherit from SystemWindow
    virtual bool          PrevButtonPressed() const override;
    virtual bool          NextButtonPressed() const override;
};

class AbstractSwLabDlg_Impl  : public AbstractSwLabDlg
{
    DECL_ABSTDLG_BASE(AbstractSwLabDlg_Impl,SwLabDlg)
    virtual void                SetCurPageId( sal_uInt16 nId ) override;
    virtual void                SetCurPageId( const OString &rName ) override;
    virtual const SfxItemSet*   GetOutputItemSet() const override;
    virtual const sal_uInt16*       GetInputRanges( const SfxItemPool& pItem ) override;
    virtual void                SetInputSet( const SfxItemSet* pInSet ) override;
        //From class Window.
    virtual void        SetText( const OUString& rStr ) override;
    virtual const OUString& GetBusinessCardStr() const override;
    virtual Printer *GetPrt() override;
};

class AbstractSwSelGlossaryDlg_Impl : public AbstractSwSelGlossaryDlg
{
    DECL_ABSTDLG_BASE(AbstractSwSelGlossaryDlg_Impl,SwSelGlossaryDlg)
    virtual void InsertGlos(const OUString &rRegion, const OUString &rGlosName) override;    // inline
    virtual sal_Int32 GetSelectedIdx() const override;  // inline
    virtual void SelectEntryPos(sal_Int32 nIdx) override;   // inline
};

class AbstractSwAutoFormatDlg_Impl : public AbstractSwAutoFormatDlg
{
protected:
    std::unique_ptr<SwAutoFormatDlg, o3tl::default_delete<SwAutoFormatDlg>> m_xDlg;
public:
    explicit AbstractSwAutoFormatDlg_Impl(SwAutoFormatDlg* p)
        : m_xDlg(p)
    {
    }
    virtual short Execute() override;
    virtual SwTableAutoFormat* FillAutoFormatOfIndex() const override;
};

class AbstractSwFieldDlg_Impl : public AbstractSwFieldDlg
{
    DECL_ABSTDLG_BASE(AbstractSwFieldDlg_Impl,SwFieldDlg )
    virtual void                SetCurPageId( sal_uInt16 nId ) override;
    virtual void                SetCurPageId( const OString &rName ) override;
    virtual const SfxItemSet*   GetOutputItemSet() const override;
    virtual const sal_uInt16*   GetInputRanges( const SfxItemPool& pItem ) override;
    virtual void                SetInputSet( const SfxItemSet* pInSet ) override;
        //From class Window.
    virtual void                SetText( const OUString& rStr ) override;
    virtual void                Start() override;  //this method from SfxTabDialog
    virtual void                ShowReferencePage() override;
    virtual void                Initialize(SfxChildWinInfo *pInfo) override;
    virtual void                ReInitDlg() override;
    virtual void                ActivateDatabasePage() override;
    virtual vcl::Window *            GetWindow() override; //this method is added for return a Window type pointer
};

class AbstractSwRenameXNamedDlg_Impl : public AbstractSwRenameXNamedDlg
{
protected:
    std::unique_ptr<SwRenameXNamedDlg> m_xDlg;
public:
    explicit AbstractSwRenameXNamedDlg_Impl(SwRenameXNamedDlg* p)
        : m_xDlg(p)
    {
    }
    virtual short Execute() override;
    virtual void SetForbiddenChars( const OUString& rSet ) override;
    virtual void SetAlternativeAccess(
             css::uno::Reference< css::container::XNameAccess > & xSecond,
             css::uno::Reference< css::container::XNameAccess > & xThird ) override;
};

class AbstractSwModalRedlineAcceptDlg_Impl : public AbstractSwModalRedlineAcceptDlg
{
    DECL_ABSTDLG_BASE(AbstractSwModalRedlineAcceptDlg_Impl,SwModalRedlineAcceptDlg )
    virtual void            AcceptAll( bool bAccept ) override;
};

class SwGlossaryDlg;
class AbstractGlossaryDlg_Impl : public AbstractGlossaryDlg
{
    DECL_ABSTDLG_BASE(AbstractGlossaryDlg_Impl,SwGlossaryDlg)
    virtual OUString        GetCurrGrpName() const override;
    virtual OUString        GetCurrShortName() const override;
};

class SwFieldInputDlg;
class AbstractFieldInputDlg_Impl : public AbstractFieldInputDlg
{
    DECL_ABSTDLG_BASE(AbstractFieldInputDlg_Impl,SwFieldInputDlg)
    //from class SalFrame
    virtual void          SetWindowState( const OString & rStr ) override;
    virtual OString       GetWindowState() const override;
    virtual void          EndDialog(sal_Int32) override;
    virtual bool          PrevButtonPressed() const override;
    virtual bool          NextButtonPressed() const override;
};

class SwInsFootNoteDlg;
class AbstractInsFootNoteDlg_Impl : public AbstractInsFootNoteDlg
{
    DECL_ABSTDLG_BASE(AbstractInsFootNoteDlg_Impl,SwInsFootNoteDlg)
    virtual OUString        GetFontName() override;
    virtual bool            IsEndNote() override;
    virtual OUString        GetStr() override;
    //from class Window
    virtual void    SetHelpId( const OString& sHelpId ) override;
    virtual void    SetText( const OUString& rStr ) override;
};

class SwInsTableDlg;
class AbstractInsTableDlg_Impl : public AbstractInsTableDlg
{
protected:
    std::unique_ptr<SwInsTableDlg> m_xDlg;
public:
    explicit AbstractInsTableDlg_Impl(SwInsTableDlg* p)
        : m_xDlg(p)
    {
    }
    virtual short Execute() override;
    virtual void            GetValues( OUString& rName, sal_uInt16& rRow, sal_uInt16& rCol,
                                SwInsertTableOptions& rInsTableFlags, OUString& rTableAutoFormatName,
                                SwTableAutoFormat *& prTAFormat ) override;
};

class SwJavaEditDialog;
class AbstractJavaEditDialog_Impl : public AbstractJavaEditDialog
{
    DECL_ABSTDLG_BASE(AbstractJavaEditDialog_Impl,SwJavaEditDialog)
    virtual OUString            GetScriptText() const override;
    virtual OUString            GetScriptType() const override;
    virtual bool                IsUrl() const override;
    virtual bool                IsNew() const override;
    virtual bool                IsUpdate() const override;
};

class SwMailMergeDlg;
class AbstractMailMergeDlg_Impl : public AbstractMailMergeDlg
{
    DECL_ABSTDLG_BASE(AbstractMailMergeDlg_Impl,SwMailMergeDlg)
    virtual DBManagerOptions GetMergeType() override ;
    virtual const OUString& GetSaveFilter() const override;
    virtual const css::uno::Sequence< css::uno::Any > GetSelection() const override ;
    virtual css::uno::Reference< css::sdbc::XResultSet> GetResultSet() const override;
    virtual bool IsSaveSingleDoc() const override;
    virtual bool IsGenerateFromDataBase() const override;
    virtual OUString GetColumnName() const override;
    virtual OUString GetTargetURL() const override;
};

class SwMailMergeCreateFromDlg;
class AbstractMailMergeCreateFromDlg_Impl : public AbstractMailMergeCreateFromDlg
{
    DECL_ABSTDLG_BASE(AbstractMailMergeCreateFromDlg_Impl,SwMailMergeCreateFromDlg)
    virtual bool    IsThisDocument() const override ;
};

class SwMailMergeFieldConnectionsDlg;
class AbstractMailMergeFieldConnectionsDlg_Impl : public AbstractMailMergeFieldConnectionsDlg
{
    DECL_ABSTDLG_BASE(AbstractMailMergeFieldConnectionsDlg_Impl,SwMailMergeFieldConnectionsDlg)
    virtual bool    IsUseExistingConnections() const override ;
};

class SwMultiTOXTabDialog;
class AbstractMultiTOXTabDialog_Impl : public AbstractMultiTOXTabDialog
{
    DECL_ABSTDLG_BASE(AbstractMultiTOXTabDialog_Impl,SwMultiTOXTabDialog)
    virtual CurTOXType          GetCurrentTOXType() const override ;
    virtual SwTOXDescription&   GetTOXDescription(CurTOXType eTOXTypes) override;
    //from SfxTabDialog
    virtual const SfxItemSet*   GetOutputItemSet() const override;
};

class SwEditRegionDlg;
class AbstractEditRegionDlg_Impl : public AbstractEditRegionDlg
{
    DECL_ABSTDLG_BASE(AbstractEditRegionDlg_Impl,SwEditRegionDlg)
    virtual void    SelectSection(const OUString& rSectionName) override;
};

class SwInsertSectionTabDialog;
class AbstractInsertSectionTabDialog_Impl : public AbstractInsertSectionTabDialog
{
    DECL_ABSTDLG_BASE(AbstractInsertSectionTabDialog_Impl,SwInsertSectionTabDialog)
    virtual void        SetSectionData(SwSectionData const& rSect) override;
};

class SwIndexMarkFloatDlg;
class AbstractIndexMarkFloatDlg_Impl : public AbstractMarkFloatDlg
{
    DECL_ABSTDLG_BASE(AbstractIndexMarkFloatDlg_Impl,SwIndexMarkFloatDlg)
    virtual void    ReInitDlg(SwWrtShell& rWrtShell) override;
    virtual vcl::Window *            GetWindow() override; //this method is added for return a Window type pointer
};

class SwAuthMarkFloatDlg;
class AbstractAuthMarkFloatDlg_Impl : public AbstractMarkFloatDlg
{
    DECL_ABSTDLG_BASE(AbstractAuthMarkFloatDlg_Impl,SwAuthMarkFloatDlg)
    virtual void    ReInitDlg(SwWrtShell& rWrtShell) override;
    virtual vcl::Window *            GetWindow() override; //this method is added for return a Window type pointer
};

class SwMailMergeWizard;
class AbstractMailMergeWizard_Impl : public AbstractMailMergeWizard
{
    VclPtr<SwMailMergeWizard> pDlg;
    Link<Dialog&,void>        aEndDlgHdl;

    DECL_LINK( EndDialogHdl, Dialog&, void );
public:
    explicit AbstractMailMergeWizard_Impl( SwMailMergeWizard* p )
     : pDlg(p)
     {}
    virtual         ~AbstractMailMergeWizard_Impl() override;
    virtual void    dispose() override;
    virtual void    StartExecuteModal( const Link<Dialog&,void>& rEndDialogHdl ) override;
    virtual sal_Int32 GetResult() override;

    virtual OUString            GetReloadDocument() const override;
    virtual void                ShowPage( sal_uInt16 nLevel ) override;
    virtual sal_uInt16          GetRestartPage() const override;
};

//AbstractDialogFactory_Impl implementations
class SwAbstractDialogFactory_Impl : public SwAbstractDialogFactory
{

public:
    virtual ~SwAbstractDialogFactory_Impl() {}

    virtual VclPtr<SfxAbstractDialog> CreateNumFormatDialog(vcl::Window* pParent, const SfxItemSet& rAttr) override;
    virtual VclPtr<SfxAbstractDialog> CreateSwDropCapsDialog(vcl::Window* pParent, const SfxItemSet& rSet) override;
    virtual VclPtr<SfxAbstractDialog> CreateSwBackgroundDialog(vcl::Window* pParent, const SfxItemSet& rSet) override;
    virtual VclPtr<AbstractSwWordCountFloatDlg> CreateSwWordCountDialog(SfxBindings* pBindings,
        SfxChildWindow* pChild, vcl::Window *pParent, SfxChildWinInfo* pInfo) override;
    virtual VclPtr<AbstractSwInsertAbstractDlg> CreateSwInsertAbstractDlg() override;
    virtual VclPtr<SfxAbstractDialog> CreateSwAddressAbstractDlg(vcl::Window* pParent, const SfxItemSet& rSet) override;
    virtual VclPtr<AbstractSwAsciiFilterDlg>  CreateSwAsciiFilterDlg(weld::Window* pParent, SwDocShell& rDocSh,
                                                                SvStream* pStream) override;
    virtual VclPtr<VclAbstractDialog> CreateSwInsertBookmarkDlg( vcl::Window *pParent, SwWrtShell &rSh, SfxRequest& rReq ) override;
    virtual VclPtr<AbstractSwBreakDlg> CreateSwBreakDlg(weld::Window *pParent, SwWrtShell &rSh) override;
    virtual VclPtr<VclAbstractDialog> CreateSwChangeDBDlg(SwView& rVw) override;
    virtual VclPtr<SfxAbstractTabDialog>  CreateSwCharDlg(vcl::Window* pParent, SwView& pVw, const SfxItemSet& rCoreSet,
        SwCharDlgMode nDialogMode, const OUString* pFormatStr = nullptr) override;
    virtual VclPtr<AbstractSwConvertTableDlg> CreateSwConvertTableDlg(SwView& rView, bool bToTable) override;
    virtual VclPtr<VclAbstractDialog> CreateSwCaptionDialog ( vcl::Window *pParent, SwView &rV) override;
    virtual VclPtr<AbstractSwInsertDBColAutoPilot> CreateSwInsertDBColAutoPilot(SwView& rView,
        css::uno::Reference< css::sdbc::XDataSource> rxSource,
        css::uno::Reference<css::sdbcx::XColumnsSupplier> xColSupp,
        const SwDBData& rData) override;
    virtual VclPtr<SfxAbstractTabDialog> CreateSwFootNoteOptionDlg(vcl::Window *pParent, SwWrtShell &rSh) override;

    virtual VclPtr<AbstractDropDownFieldDialog> CreateDropDownFieldDialog(SwWrtShell &rSh,
        SwField* pField, bool bPrevButton, bool bNextButton) override;
    virtual VclPtr<SfxAbstractTabDialog> CreateSwEnvDlg ( vcl::Window* pParent, const SfxItemSet& rSet, SwWrtShell* pWrtSh, Printer* pPrt, bool bInsert ) override;
    virtual VclPtr<AbstractSwLabDlg> CreateSwLabDlg(const SfxItemSet& rSet,
                                                     SwDBManager* pDBManager, bool bLabel) override;

    virtual SwLabDlgMethod GetSwLabDlgStaticMethod () override;
    virtual VclPtr<SfxAbstractTabDialog> CreateSwParaDlg ( vcl::Window *pParent,
                                                    SwView& rVw,
                                                    const SfxItemSet& rCoreSet,
                                                    bool bDraw,
                                                    const OString& sDefPage = OString() ) override;

    virtual VclPtr<VclAbstractDialog> CreateSwAutoMarkDialog(vcl::Window *pParent, SwWrtShell &rSh) override;
    virtual VclPtr<AbstractSwSelGlossaryDlg> CreateSwSelGlossaryDlg(const OUString &rShortName) override;
    virtual VclPtr<VclAbstractDialog> CreateSwSortingDialog(weld::Window * pParent, SwWrtShell &rSh) override;
    virtual VclPtr<VclAbstractDialog> CreateSwTableHeightDialog(weld::Window *pParent, SwWrtShell &rSh) override;
    virtual VclPtr<VclAbstractDialog> CreateSwColumnDialog(vcl::Window *pParent, SwWrtShell &rSh) override;
    virtual VclPtr<AbstractSplitTableDialog> CreateSplitTableDialog(weld::Window* pParent, SwWrtShell &rSh) override;

    virtual VclPtr<AbstractSwAutoFormatDlg> CreateSwAutoFormatDlg(weld::Window* pParent, SwWrtShell* pShell,
                                                                  bool bSetAutoFormat = true,
                                                                  const SwTableAutoFormat* pSelFormat = nullptr) override;
    virtual VclPtr<SfxAbstractDialog> CreateSwBorderDlg (vcl::Window* pParent, SfxItemSet& rSet, SwBorderModes nType ) override;

    virtual VclPtr<SfxAbstractDialog> CreateSwWrapDlg ( vcl::Window* pParent, SfxItemSet& rSet, SwWrtShell* pSh ) override;
    virtual VclPtr<VclAbstractDialog> CreateSwTableWidthDlg(weld::Window *pParent, SwTableFUNC &rFnc) override;
    virtual VclPtr<SfxAbstractTabDialog> CreateSwTableTabDlg(vcl::Window* pParent,
        const SfxItemSet* pItemSet, SwWrtShell* pSh) override;
    virtual VclPtr<AbstractSwFieldDlg> CreateSwFieldDlg(SfxBindings* pB, SwChildWinWrapper* pCW, vcl::Window *pParent) override;
    virtual VclPtr<SfxAbstractDialog>   CreateSwFieldEditDlg ( SwView& rVw ) override;
    virtual VclPtr<AbstractSwRenameXNamedDlg> CreateSwRenameXNamedDlg(weld::Window* pParent,
        css::uno::Reference< css::container::XNamed > & xNamed,
        css::uno::Reference< css::container::XNameAccess > & xNameAccess) override;
    virtual VclPtr<AbstractSwModalRedlineAcceptDlg> CreateSwModalRedlineAcceptDlg(vcl::Window *pParent) override;

    virtual VclPtr<VclAbstractDialog>          CreateTableMergeDialog(weld::Window* pParent, bool& rWithPrev) override;
    virtual VclPtr<SfxAbstractTabDialog>       CreateFrameTabDialog( const OUString &rDialogType,
                                                SfxViewFrame *pFrame, vcl::Window *pParent,
                                                const SfxItemSet& rCoreSet,
                                                bool bNewFrame  = true,
                                                const OString& sDefPage = OString()) override;
    virtual VclPtr<SfxAbstractApplyTabDialog>  CreateTemplateDialog(
                                                vcl::Window *pParent,
                                                SfxStyleSheetBase&  rBase,
                                                SfxStyleFamily      nRegion,
                                                const OString&      sPage,
                                                SwWrtShell*         pActShell,
                                                bool                bNew) override;
    virtual VclPtr<AbstractGlossaryDlg>        CreateGlossaryDlg(SfxViewFrame* pViewFrame,
                                                SwGlossaryHdl* pGlosHdl,
                                                SwWrtShell *pWrtShell) override;
    virtual VclPtr<AbstractFieldInputDlg>        CreateFieldInputDlg(vcl::Window *pParent,
        SwWrtShell &rSh, SwField* pField, bool bPrevButton, bool bNextButton) override;
    virtual VclPtr<AbstractInsFootNoteDlg>     CreateInsFootNoteDlg(
        vcl::Window * pParent, SwWrtShell &rSh, bool bEd = false) override;
    virtual VclPtr<VclAbstractDialog>         CreateTitlePageDlg ( vcl::Window * pParent ) override;
    virtual VclPtr<VclAbstractDialog>         CreateVclSwViewDialog(SwView& rView) override;
    virtual VclPtr<AbstractInsTableDlg>        CreateInsTableDlg(SwView& rView) override;
    virtual VclPtr<AbstractJavaEditDialog>     CreateJavaEditDialog(vcl::Window* pParent,
        SwWrtShell* pWrtSh) override;
    virtual VclPtr<AbstractMailMergeDlg>       CreateMailMergeDlg(
                                                vcl::Window* pParent, SwWrtShell& rSh,
                                                const OUString& rSourceName,
                                                const OUString& rTableName,
                                                sal_Int32 nCommandType,
                                                const css::uno::Reference< css::sdbc::XConnection>& xConnection ) override;
    virtual VclPtr<AbstractMailMergeCreateFromDlg>     CreateMailMergeCreateFromDlg(vcl::Window* pParent) override;
    virtual VclPtr<AbstractMailMergeFieldConnectionsDlg> CreateMailMergeFieldConnectionsDlg(vcl::Window* pParent) override;
    virtual VclPtr<VclAbstractDialog>          CreateMultiTOXMarkDlg(vcl::Window* pParent, SwTOXMgr &rTOXMgr) override;
    virtual VclPtr<SfxAbstractTabDialog>       CreateOutlineTabDialog(vcl::Window* pParent, const SfxItemSet* pSwItemSet,
                                                SwWrtShell &) override;
    virtual VclPtr<SfxAbstractTabDialog>       CreateSvxNumBulletTabDialog(vcl::Window* pParent,
                                                const SfxItemSet* pSwItemSet,
                                                SwWrtShell &) override;
    virtual VclPtr<AbstractMultiTOXTabDialog>  CreateMultiTOXTabDialog(
                                                vcl::Window* pParent, const SfxItemSet& rSet,
                                                SwWrtShell &rShell,
                                                SwTOXBase* pCurTOX,
                                                bool bGlobal) override;
    virtual VclPtr<AbstractEditRegionDlg>      CreateEditRegionDlg(vcl::Window* pParent, SwWrtShell& rWrtSh) override;
    virtual VclPtr<AbstractInsertSectionTabDialog>     CreateInsertSectionTabDialog(
        vcl::Window* pParent, const SfxItemSet& rSet, SwWrtShell& rSh) override;
    virtual VclPtr<AbstractMarkFloatDlg>       CreateIndexMarkFloatDlg(
                                                       SfxBindings* pBindings,
                                                       SfxChildWindow* pChild,
                                                       vcl::Window *pParent,
                                                       SfxChildWinInfo* pInfo) override;
    virtual VclPtr<AbstractMarkFloatDlg>       CreateAuthMarkFloatDlg(
                                                       SfxBindings* pBindings,
                                                       SfxChildWindow* pChild,
                                                       vcl::Window *pParent,
                                                       SfxChildWinInfo* pInfo) override;
    virtual VclPtr<VclAbstractDialog>         CreateIndexMarkModalDlg(
                                                vcl::Window *pParent, SwWrtShell& rSh, SwTOXMark* pCurTOXMark ) override;

    virtual VclPtr<AbstractMailMergeWizard>    CreateMailMergeWizard(SwView& rView, std::shared_ptr<SwMailMergeConfigItem>& rConfigItem) override;

    virtual GlossaryGetCurrGroup        GetGlossaryCurrGroupFunc() override;
    virtual GlossarySetActGroup         SetGlossaryActGroupFunc() override;

    // For TabPage
    virtual CreateTabPage               GetTabPageCreatorFunc( sal_uInt16 nId ) override;

    virtual void ExecuteMMResultSaveDialog() override;
    virtual void ExecuteMMResultPrintDialog() override;
    virtual void ExecuteMMResultEmailDialog() override;
};

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
