////////////////////////////////////////////////////////////////////////////////
//
// GTK project wizard
//
////////////////////////////////////////////////////////////////////////////////

// globals
GtkPathDefault    <- _T("$(#gtk)");
GtkPathDefaultInc <- _T("$(#gtk.include)");
GtkPathDefaultLib <- _T("$(#gtk.lib)");
GtkPath <- _T("");
// GtkVersion <- 1; // 0 - GTK+, 1 - GTK+-2.0

function BeginWizard()
{
    local intro_msg = _T("Welcome to the new GTK project wizard!\n" +
                         "This wizard will guide you to create a new GTK project\n" +
                         "using the GTK cross-platform GUI toolkit\n\n" +
                         "When you're ready to proceed, please click \"Next\"...");

    local gtkpath_msg = _T("Please select the location of GTK on your computer.\n" +
                           "This is the top-level folder where GTK was installed.\n" +
                           "To help you, this folder must contain the subfolders\n" +
                           "\"include\" and \"lib\".");

    Wizard.AddInfoPage(_T("GtkIntro"), intro_msg);
    Wizard.AddProjectPathPage();
    if (PLATFORM == PLATFORM_MSW)
    {
        Wizard.AddGenericSelectPathPage(_T("GtkPath"), gtkpath_msg, _T("GTK's location:"), GtkPathDefault);
    }
    /*else
    {
        Wizard.AddGenericSingleChoiceListPage(_T("GtkVersionPage"), _T("Please select the GTK+ version you want to use."), _T("GTK+ 1.x;GTK+ 2.x"), GtkVersion); // select GTK+ version
    }*/
    Wizard.AddCompilerPage(_T(""), _T("gcc*"), true, true);
}

////////////////////////////////////////////////////////////////////////////////
// Gtk's path page
////////////////////////////////////////////////////////////////////////////////

function OnLeave_GtkPath(fwd)
{
    if (fwd)
    {
        local dir         = Wizard.GetTextControlValue(_T("txtFolder")); // txtFolder is the text control in GenericSelectPathPage
        local dir_nomacro = VerifyDirectory(dir);

        if (dir_nomacro.IsEmpty())
            return false;

        // verify include dependencies
        local dir_nomacro_inc = GetCompilerIncludeDir(dir, GtkPathDefault, GtkPathDefaultInc);
        if (dir_nomacro_inc.IsEmpty())
            return false;
        if (!VerifyFile(dir_nomacro_inc + wxFILE_SEP_PATH + _T("gtk-3.0") + wxFILE_SEP_PATH +_T("gtk"), _T("gtk.h"), _T("GTK's include")))
            return false;

        // verify library dependencies
        local dir_nomacro_lib = GetCompilerLibDir(dir, GtkPathDefault, GtkPathDefaultLib);
        if (dir_nomacro_lib.IsEmpty())
            return false;
       /* if (!VerifyLibFile(dir_nomacro_lib, _T("gtk-win32-2.0"), _T("GTK's")))
            return false;*/
             /*if (!VerifyLibFile(dir_nomacro_lib, _T("gtk-win32-3.0"), _T("GTK's")))
            return false;*/


        GtkPath = dir; // Remember the original selection.

        local is_macro = _T("");

        // try to resolve the include directory as macro
        is_macro = GetCompilerIncludeMacro(dir, GtkPathDefault, GtkPathDefaultInc);
        if (is_macro.IsEmpty())
        {
            // not possible -> use the real inc path we had computed instead
            GtkPathDefaultInc = dir_nomacro_inc;
        }

        // try to resolve the library directory as macro
        is_macro = GetCompilerLibMacro(dir, GtkPathDefault, GtkPathDefaultLib);
        if (is_macro.IsEmpty())
        {
            // not possible -> use the real lib path we had computed instead
            GtkPathDefaultLib = dir_nomacro_lib;
        }
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////
// Gtk's version page (For *nix users)
////////////////////////////////////////////////////////////////////////////////

function OnLeave_GtkVersionPage(fwd)
{
    if (fwd)
    {
        GtkVersion = Wizard.GetListboxSelection(_T("GenericChoiceList"));
    }
    return true;
}

// return the files this project contains
function GetFilesDir()
{
    return _T("gtk/files");
}

// setup the already created project
function SetupProject(project)
{
    if (PLATFORM == PLATFORM_MSW)
    {
        project.AddIncludeDir(GtkPathDefaultInc);
        project.AddIncludeDir(GtkPathDefaultInc + wxFILE_SEP_PATH + _T("gtk-3.0"));
        project.AddIncludeDir(GtkPathDefaultInc + wxFILE_SEP_PATH + _T("cairo"));
        project.AddIncludeDir(GtkPathDefaultInc + wxFILE_SEP_PATH + _T("gdk"));
        project.AddIncludeDir(GtkPathDefaultInc + wxFILE_SEP_PATH + _T("glib-2.0"));
        // Notice GtkPathDefault*Lib* at some positions. This is correct as of 2.8.20
        project.AddIncludeDir(GtkPathDefaultLib + wxFILE_SEP_PATH + _T("glib-2.0") + wxFILE_SEP_PATH + _T("include"));
        project.AddIncludeDir(GtkPathDefaultInc + wxFILE_SEP_PATH + _T("pango-1.0"));
        project.AddIncludeDir(GtkPathDefaultLib + wxFILE_SEP_PATH + _T("gtk-3.0")  + wxFILE_SEP_PATH + _T("include"));
        project.AddIncludeDir(GtkPathDefaultInc + wxFILE_SEP_PATH + _T("atk-1.0"));
        if ( IO.DirectoryExists(GtkPathDefaultInc + wxFILE_SEP_PATH + _T("gdk-pixbuf-2.0")) )
            project.AddIncludeDir(GtkPathDefaultInc + wxFILE_SEP_PATH + _T("gdk-pixbuf-2.0"));

        project.AddLibDir(GtkPathDefaultLib);

        // add link libraries
       /* project.AddLinkLib(_T("gtk-win32-2.0"));
      generate with pkg-config commande  on MS Windows. the command was pkg-config gtk+-3.0 --libs and current directory was
       gtk3.0/bin
       -lgtk-3 -lgdk-3 -lgdi32 -limm32 -lshell32 -lole32 -Wl,-luuid -lpangocairo-1.0
        -lpangoft2-1.0 -lfreetype -lfontconfig -lpangowin32-1.0 -lgdi32 -lpango-1.0 -lm -latk-1.0 -lcairo-gobject -lcairo
        -lgdk_pixbuf-2.0 -lgio-2.0 -lgobject-2.0 -lglib-2.0 -lintl

        project.AddLinkLib(_T("gtk-3"));
        project.AddLinkLib(_T("gdk-3"));
        project.AddLinkLib(_T("imm32"));
        project.AddLinkLib(_T("shell32"));
        project.AddLinkLib(_T("ole32"));
        project.AddLinkLib(_T("Wl"));
        project.AddLinkLib(_T("uuid"));
        project.AddLinkLib(_T("pangocairo-1.0"));
        project.AddLinkLib(_T("pangoft2-1.0"));
        project.AddLinkLib(_T("freetype"));
        project.AddLinkLib(_T("fontconfig"));
        project.AddLinkLib(_T("pangowin32-1.0"));
        project.AddLinkLib(_T("gdi32"));
        project.AddLinkLib(_T("m"));
        project.AddLinkLib(_T("atk-1.0"));
        project.AddLinkLib(_T("cairo-gobject"));
        project.AddLinkLib(_T("cairo"));
        project.AddLinkLib(_T("gdk_pixbuf-2.0"));
        project.AddLinkLib(_T("gio-2.0"));
        project.AddLinkLib(_T("gobject-2.0"));
        project.AddLinkLib(_T("glib-2.0"));
        project.AddLinkLib(_T("intl"));
        //project.AddLinkLib(_T("glib-2.0"));*/

        project.AddLibDir(GtkPathDefaultLib);

        // add link libraries
        project.AddLinkLib(_T("gtk-win32-3.0"));
        project.AddLinkLib(_T("gobject-2.0"));
        project.AddLinkLib(_T("glib-2.0"));

        // Notice: there are more libs required as the app gets more complex, e.g.:
        // pangocairo-1.0.lib, pangocairo-1.0.lib, libatk-1.0.dll.a,
        // gdk_pixbuf-2.0.lib, gdk-win32-2.0.lib,  pango-1.0.lib,
        // gmodule-2.0.lib,    gthread-2.0.lib,    cairo.lib,
        // pangoft2-1.0.lib    (...)

        project.AddCompilerOption(_T("-mms-bitfields"));
    }
    else
    {
        /*if (GtkVersion == 1)
        {*/
        project.AddCompilerOption(_T("`pkg-config gtk+-3.0 --cflags`"));
        project.AddLinkerOption(_T("`pkg-config gtk+-3.0 --libs`"));
        /*}
        else
        {
            project.AddCompilerOption(_T("`pkg-config gtk+ --cflags`"));
            project.AddLinkerOption(_T("`pkg-config gtk+ --libs`"));
        }*/
   }

    // enable compiler warnings (project-wide)
    WarningsOn(project, Wizard.GetCompilerID());

    // Debug
    local target = project.GetBuildTarget(Wizard.GetDebugName());
    if (!IsNull(target))
    {
        target.SetTargetType(ttConsoleOnly); // ttConsoleOnly: console for debugging
        target.SetOutputFilename(Wizard.GetDebugOutputDir() + Wizard.GetProjectName() + DOT_EXT_EXECUTABLE);
        // enable generation of debugging symbols for target
        DebugSymbolsOn(target, Wizard.GetCompilerID());
    }

    // Release
    target = project.GetBuildTarget(Wizard.GetReleaseName());
    if (!IsNull(target))
    {
        target.SetTargetType(ttExecutable); // ttExecutable: no console
        target.SetOutputFilename(Wizard.GetReleaseOutputDir() + Wizard.GetProjectName() + DOT_EXT_EXECUTABLE);
        // enable optimizations for target
        OptimizationsOn(target, Wizard.GetCompilerID());
    }

    return true;
}
